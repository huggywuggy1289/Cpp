#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> nick;            // uid는 최종 닉네임
    vector<pair<string, bool>> events;
    events.reserve(record.size());

    for (const auto& line : record) {
        istringstream iss(line);
        string cmd, uid, name;
        iss >> cmd >> uid;
        if (cmd == "Enter") {
            iss >> name;
            nick[uid] = name;
            events.push_back({uid, true});
        } else if (cmd == "Leave") {
            events.push_back({uid, false});
        } else { // Change
            iss >> name;
            nick[uid] = name;
        }
    }

    vector<string> answer;
    answer.reserve(events.size());
    for (const auto& [uid, enter] : events) {
        string msg = nick[uid] + (enter ? "님이 들어왔습니다." : "님이 나갔습니다.");
        answer.push_back(move(msg));
    }
    return answer;
}
