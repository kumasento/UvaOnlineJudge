
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Event {
    int Q_num, Period, Time;
    friend bool operator < (Event a, Event b) {
        if (a.Time == b.Time)
            return a.Q_num > b.Q_num;
        else 
            return a.Time > b.Time;
    }
};

int main() {
    freopen("1203.Argus.dat", "r", stdin);

    string marker; cin >> marker;
    
    priority_queue<Event> q;
    
    while (marker != string("#")) {
        Event event;
        cin >> event.Q_num >> event.Period;

        event.Time = event.Period;
        q.push(event);

        cin >> marker;
    }

    int K; cin >> K;

    for (int i = 0; i < K; i++) {
        Event e = q.top();
        q.pop();

        cout << e.Q_num << endl;

        e.Time += e.Period;
        q.push(e);
    }

    return 0;
}
