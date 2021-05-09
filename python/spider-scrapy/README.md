# scrapy

its official website is https://docs.scrapy.org/en/latest

tutorial: https://docs.scrapy.org/en/latest/intro/tutorial.html

## install scrapy
```sh
pip3 install scrapy
```

## create the first project
```sh
scrapy genspider Demo http://quotes.toscrape.com/tag/humor/
```

```sh
scrapy startproject tutorial

cd tutorial/

cd spiders/
scrapy genspider quotes http://quotes.toscrape.com/page/1/

scrapy crawl quotes -o out.jl -s FEED_EXPORT_ENCODING=utf-8
```

## scrapy shell
```sh
scrapy shell 'http://quotes.toscrape.com/page/1/'
```


## FilePipeline
items.py
```py
import scrapy

class FileDemoItem(scrapy.Item):
    text = scrapy.Field()
    author = scrapy.Field()
    tags = scrapy.Field()
```

pipelines.py
```py
## refer to https://book.apeland.cn/details/409/
## https://docs.scrapy.org/en/latest/topics/item-pipeline.html#writing-your-own-item-pipeline
class FileDemoPipeline:
    def __init__(self):
          self.fp = None

    def open_spider(self, spider):
        self.fp = open('./data.txt', 'w')

    def process_item(self, item, spider):
        self.fp.write(item['author'] + ': ' + item['text'] + ' <' + ', '.join(item['tags']) + '>' + '\n')
        return item

    def close_spider(self, spider):
        self.fp.close()
```

settings.py
```py
ITEM_PIPELINES = {
    'tutorial.pipelines.FileDemoPipeline': 200,
}
```

FileDemo.py
```py
import scrapy
from tutorial.items import FileDemoItem


class FiledemoSpider(scrapy.Spider):
    name = 'FileDemo'
    allowed_domains = ['quotes.toscrape.com']
    start_urls = [
            'http://quotes.toscrape.com/',
    ]

    def parse(self, response):
        for quote in response.xpath('//div[@class="quote"]'):
            item = FileDemoItem()
            item['text'] = quote.xpath('./span[@class="text"]/text()').extract_first()
            item['author'] = quote.xpath('.//small[@class="author"]/text()').extract_first()
            item['tags'] = quote.xpath('.//div[@class="tags"]/a[@class="tag"]/text()').extract()
            yield item

        next_page_url = response.xpath('//li[@class="next"]/a/@href').extract_first()
        if next_page_url is not None:
            yield scrapy.Request(response.urljoin(next_page_url))
```

run: `crapy crawl FileDemo`


## ImagePipeline
to avoid "Disabled YangziImagesPipeline: ImagesPipeline requires installing Pillow 4.0.0 or later"
```sh
pip3 install pillow
```

items.py
```py
import scrapy

class ImageDemoItem(scrapy.Item):
    src = scrapy.Field()
```

pipelines.py
```py
## refer to https://book.apeland.cn/details/486/
## https://docs.scrapy.org/en/latest/topics/media-pipeline.html#scrapy.pipelines.images.ImagesPipeline
from scrapy.pipelines.images import ImagesPipeline
import scrapy
class ImageDemoPipeline(ImagesPipeline):

    def get_media_requests(self, item, info):
        yield scrapy.Request(item['src'])

	def file_path(self, request, response=None, info=None, *, item=None):
        url = request.url
        file_name = url.split('/')[-1]
        return file_name

    ## the return value will pass to the next pipeline
    def item_completed(self, results, item, info):
        return item
```

settings.py
```py
ROBOTSTXT_OBEY = True

USER_AGENT = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36"

HTTPERROR_ALLOWED_CODES = [403, 404]

ITEM_PIPELINES = {
    'tutorial.pipelines.ImageDemoPipeline': 300,
}

IMAGES_STORE = './images'
```

ImagedemoSpider.py
```py
import scrapy
from tutorial.items import ImageDemoItem

class ImagedemoSpider(scrapy.Spider):
    name = 'ImageDemo'
    allowed_domains = ['www.ruanyifeng.com']
    start_urls = ['http://www.ruanyifeng.com/blog/2017/07/neural-network.html']

    def parse(self, response):
        imgs = response.xpath('//*[@id="main-content"]//img/@src').getall()
        print(imgs)
        for i in imgs:
            item = ImageDemoItem()
            item['src'] = i
            yield item
```

run: `scrapy crawl ImageDemo`


## FAQ
add the following line to settings.py to avoid not allowed

```py
ROBOTSTXT_OBEY = False

HTTPERROR_ALLOWED_CODES = [403, 404]
USER_AGENT = 'quotesbot (+http://www.yourdomain.com)'
USER_AGENT = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36"
```

> typing `about:version` on chrome to check user agent.
> or `alert(navigator.userAgent)` on console






