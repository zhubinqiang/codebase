# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


class TutorialPipeline:
    def process_item(self, item, spider):
        return item


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



##https://book.apeland.cn/details/486/
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


