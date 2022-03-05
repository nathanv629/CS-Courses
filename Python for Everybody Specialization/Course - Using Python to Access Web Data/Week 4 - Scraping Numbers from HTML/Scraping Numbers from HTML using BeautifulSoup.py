# Nathan Van
# 2/21/2022

#import module
import requests
from bs4 import BeautifulSoup
import csv
from urllib.request import urlopen
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

# JSON get requests to url
response = requests.get("http://py4e-data.dr-chuck.net/comments_1491519.html")
# parse html content
soup = BeautifulSoup(response.text, "html.parser")
# Finding by class name
comments = soup.find_all(class_='comments')
# iterate through the list and get the text
sum, count = 0, 0
for comment in comments:
    count = count + 1
    sum = sum + float(comment.text)
print('Count', count)
print('Sum', int(sum))
