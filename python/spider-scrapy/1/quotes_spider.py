#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# **********************************************
# @file: quotes_spider.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-05-02 20:55:49
# @last modified: 2021-05-02 20:57:17
# @description: https://docs.scrapy.org/en/latest/intro/overview.html
# **********************************************

import scrapy

class QuotesSpider(scrapy.Spider):
    name = 'quotes'
    start_urls = [
        'http://quotes.toscrape.com/tag/humor/',
    ]

    def parse(self, response):
        for quote in response.css('div.quote'):
            yield {
                'author': quote.xpath('span/small/text()').get(),
                'text': quote.css('span.text::text').get(),
            }

        next_page = response.css('li.next a::attr("href")').get()
        if next_page is not None:
            yield response.follow(next_page, self.parse)


