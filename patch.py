with open('submit_acmoj/acmoj_client.py', 'r') as f:
    content = f.read()

content = content.replace(
    "def submit_git(self, problem_id: int, git_url: str) -> Optional[Dict]:",
    "def submit_code(self, problem_id: int, language: str, code: str) -> Optional[Dict]:\n        data = {\"language\": language, \"code\": code}\n        result = self._make_request(\"POST\", f\"/problem/{problem_id}/submit\", data=data)\n        if result and 'id' in result:\n            self._save_submission_id(result['id'])\n        return result\n\n    def submit_git(self, problem_id: int, git_url: str) -> Optional[Dict]:"
)

with open('submit_acmoj/acmoj_client.py', 'w') as f:
    f.write(content)
