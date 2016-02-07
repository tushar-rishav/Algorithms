import urllib2,json
from sys import stdin
from datetime import datetime

def extract(data):
	pull = 0
	for item in data["items"]:
		if item.has_key("pull_request"):
			pull += 1
	return pull
		
def main():
	org,repo,date = stdin.readline().split(' ')
	date = date.strip().split('-')
	date = map(int, date)
	d = datetime(date[-1],date[-2],date[-3])
	issue_url = "https://api.github.com/search/issues?q=repo:{}/{}+created:{}&per_page=100&page=".format(org,repo,str(d)[:-9])
	issue = 0; pull =0
	page = 1
	data = urllib2.urlopen(issue_url+str(page)).read()
	data = json.loads(data)
	count = extract(data)
	issue += data["total_count"]-count
	pull += count
	while data["incomplete_results"]:
		page += 1
		data = urllib2.urlopen(issue_url+str(page)).read()
		data = json.loads(data)
		count = extract(data)
		issue += data["total_count"]-count
		pull += count 
		
	
	print "Issues: {}".format(issue)
	print "Pull requests: {}".format(pull)

if __name__ == "__main__":
	main()
