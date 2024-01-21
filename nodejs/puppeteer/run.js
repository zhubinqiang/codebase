#!/usr/bin/env node

// https://puppeteer.bootcss.com/

const puppeteer = require('puppeteer');

(async () => {
  const browser = await puppeteer.launch({headless: false});
  const page = await browser.newPage();
  await page.goto('https://bilibili.com');
  await page.screenshot({path: 'example.png'});

  await browser.close();
})();


