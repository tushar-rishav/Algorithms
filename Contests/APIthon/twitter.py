import base64
import json
import sys
try:
    from urllib.request import urlopen, Request
    from urllib.error import HTTPError
except ImportError:
    from urllib2 import urlopen, Request, HTTPError

API_ENDPOINT = 'https://api.twitter.com'
API_VERSION = '1.1'
REQUEST_TOKEN_URL = '%s/oauth2/token' % API_ENDPOINT
REQUEST_RATE_LIMIT = '%s/%s/application/rate_limit_status.json' % \
                     (API_ENDPOINT, API_VERSION)
CONSUMER_KEY = 'CON_KEY'
CONSUMER_SECRET = 'CON_SEC'

class ClientException(Exception):
    pass


class Client(object):
    def __init__(self, consumer_key, consumer_secret):
        self.consumer_key = consumer_key
        self.consumer_secret = consumer_secret
        self.access_token = ''

    def request(self, url):
        if not self.access_token:
            self.access_token = self._get_access_token()

        request = Request(url)
        request.add_header('Authorization', 'Bearer %s' % self.access_token)
        try:
            response = urlopen(request)
        except HTTPError:
            raise ClientException

        raw_data = response.read().decode('utf-8')
        data = json.loads(raw_data)
        return data

    def rate_limit_status(self, resource=''):
        response = self.request(REQUEST_RATE_LIMIT)
        if resource:
            resource_family = resource.split('/')[1]
            return response['resources'][resource_family][resource]
        return response

    def _get_access_token(self):
        bearer_token = '%s:%s' % (self.consumer_key, self.consumer_secret)
        encoded_bearer_token = base64.b64encode(bearer_token.encode('ascii'))
        request = Request(REQUEST_TOKEN_URL)
        request.add_header('Content-Type',
                           'application/x-www-form-urlencoded;charset=UTF-8')
        request.add_header('Authorization',
                           'Basic %s' % encoded_bearer_token.decode('utf-8'))

        request_data = 'grant_type=client_credentials'.encode('ascii')
        if sys.version_info < (3,4):
            request.add_data(request_data)
        else:
            request.data = request_data

        response = urlopen(request)
        raw_data = response.read().decode('utf-8')
        data = json.loads(raw_data)
        return data['access_token']

client = Client(CONSUMER_KEY, CONSUMER_SECRET)
tweet = client.request('https://api.twitter.com/1.1/statuses/show.json?id=514611142178516993')
result = json.dumps(tweet, sort_keys=True, indent=4, separators=(',', ':'))
result = json.loads(result)
for i in result["entities"]["user_mentions"]:
	print i["screen_name"]

