import requests import json
def main(region, keyword):
list={}
response=requests.get('https://jsonmock.hackerrank.com/api/countries/search?region={}'.format(region))
data=response.text
result=json.loads(data)
for i in range(0, int(result['total_pages'])):
response=requests.get('https://jsonmock.hackerrank.com/api/countries/search?region=[]&page={}'.format(region, i+1))
data-response.text
json_data=json.loads(data)
for jin range(0,len (json_data['data'])):
if (keyword. lower() in json_data['data'][j]['name'].lower()): list[json_data['data'][j]['name']]=json_data['data'][j]['population']
list-sorted(list.items(), key-lambda kv: (kv[1], kv[0])) for i,j in list: print(str(i)+","+str(j))
if _name__=="__main__":
main("Asia", "in")