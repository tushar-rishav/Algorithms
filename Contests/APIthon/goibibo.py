import urllib,json
from sys import stdin
def main():
    a = int(raw_input())
    app_id = "APP_ID"
    app_key = "APP_KEY"
    id_list = [a]
    method="hotels.get_hotels_data";id_type="_id";
    url = "http://developer.goibibo.com/api/voyager/?";
    data = {"app_id":app_id,"app_key":app_key,"id_list":id_list,"method":method,"id_type":id_type}
    data = urllib.urlopen(url+urllib.urlencode(data)).read()
    data = json.loads(data)
    print data["data"][str(a)]["hotel_geo_node"]["name"]
if __name__ == "__main__":
    main()
