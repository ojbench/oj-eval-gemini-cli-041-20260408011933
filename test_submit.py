import requests
import os
token = os.environ.get("ACMOJ_TOKEN")
headers = {"Authorization": f"Bearer {token}", "Content-Type": "application/x-www-form-urlencoded"}
data = {"language": "cpp", "code": "#include <iostream>\nint main() { std::cout << \"Hello World\" << std::endl; return 0; }"}
response = requests.post("https://acm.sjtu.edu.cn/OnlineJudge/api/v1/problem/2672/submit", headers=headers, data=data)
print(response.status_code)
print(response.text)
