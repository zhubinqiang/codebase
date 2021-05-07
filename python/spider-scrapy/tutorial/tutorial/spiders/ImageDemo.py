import scrapy
from tutorial.items import ImageDemoItem


class ImagedemoSpider(scrapy.Spider):
    name = 'ImageDemo'
    allowed_domains = ['www.ruanyifeng.com']
    start_urls = ['http://www.ruanyifeng.com/blog/2017/07/neural-network.html']

    def parse(self, response):
        # with open('ruanyifeng.html', 'wb') as f:
        #     f.write(response.body)

        imgs = response.xpath('//*[@id="main-content"]//img/@src').getall()
        print(imgs)
        for i in imgs:
            item = ImageDemoItem()
            item['src'] = i
            yield item

    def parse_2(self, response):
        imgs = response.xpath('//*[@id="main-content"]//img/@src').getall()

        import requests
        import os
        os.makedirs('images-2')
        for i in imgs:
            r = requests.get(i, stream=True)
            if r.ok:
                name = i.split('/')[-1]
                with open(f'images-2/{name}', 'wb') as f:
                    for i in r.iter_content(chunk_size=1024):
                        f.write(i)


