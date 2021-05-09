import scrapy


# copy from https://book.apeland.cn/details/437/
class PageSpider(scrapy.Spider):
    name = 'page'
    allowed_domains = ['www.qiushibaike.com']
    start_urls = ['http://www.qiushibaike.com/']

    pageNum = 1
    url = 'https://www.qiushibaike.com/text/page/%s/'

    def parse(self, response):
        for div in response.xpath('//*[@id="content"]/div/div[2]/div'):
            #//*[@id="qiushi_tag_120996995"]/div[1]/a[2]/h2
            author=div.xpath('.//div[@class="author clearfix"]//h2/text()').extract_first()
            content=div.xpath('.//div[@class="content"]/span/text()').extract_first()

            if author and content:
                author = author.strip('\n')
                content=content.strip('\n')
                yield {
                    "author": author,
                    "content": content
                }

            print(author)
            print(content)


        #爬取所有页码数据
        if self.pageNum <= 13: #一共爬取13页（共13页）
            self.pageNum += 1
            url = format(self.url % self.pageNum)
            #递归爬取数据：callback参数的值为回调函数（将url请求后，得到的相应数据继续进行parse解析），递归调用parse函数
            yield scrapy.Request(url=url, callback=self.parse)


