import requests
import os
token = os.environ.get("ACMOJ_TOKEN")
headers = {"Authorization": f"Bearer {token}"}
response = requests.get("https://acm.sjtu.edu.cn/OnlineJudge/api/v1/submission/771728", headers=headers)
print(response.status_code)
print(response.text)
