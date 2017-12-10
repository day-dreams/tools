#! coding:utf8

import requests
import json
import sys

def main():
    ip=sys.argv[1]

    url = "http://ip.taobao.com/service/getIpInfo.php?ip=%s"%ip.strip()
    
    response=requests.get(url)

    jsonstr = response.content

    data = json.loads(jsonstr)
    data = json.dumps(data, indent=4, ensure_ascii=False)
    print data
# urllib2.

if __name__=="__main__":
    if len(sys.argv)<2:
        print "use: ipwhereis [ip]"
    else:
        main()
