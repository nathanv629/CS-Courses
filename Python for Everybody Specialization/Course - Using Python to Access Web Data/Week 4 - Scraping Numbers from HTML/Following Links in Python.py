# Nathan Van
# 2/21/2022

# import module
import urllib.request
import urllib.parse
import urllib.error
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

# JSON get requests to url
url = input('Enter URL: ')
count = input('Enter count: ')
position = input('Enter position: ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')
print('Retrieving', url)

# iterate through the list and get the text
for _ in range(int(count)):
    aTags = soup.find_all('a')
    print('Retrieving', aTags[int(position)-1]['href'])
    newURL = aTags[int(position)-1]['href']
    html = urllib.request.urlopen(newURL, context=ctx).read()
    soup = BeautifulSoup(html, 'html.parser')
