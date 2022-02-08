import requests
from bs4 import BeautifulSoup
daily_star = requests.get('https://www.thedailystar.net')
parsed_html = BeautifulSoup(daily_star.text, 'html.parser')
headlines = parsed_html.find_all('h3')
for i in headlines: 
    if len(i.text.strip()) > 0:
        print(i.text) 
        