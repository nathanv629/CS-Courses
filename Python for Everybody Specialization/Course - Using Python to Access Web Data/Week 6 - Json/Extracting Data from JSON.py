import urllib.request
import urllib.parse
import json

request = urllib.request.urlopen(
    'http://py4e-data.dr-chuck.net/comments_1491522.json')
data = json.load(request)
sum = 0
for count in data['comments']:
    sum = sum + int(count['count'])
print(sum)
