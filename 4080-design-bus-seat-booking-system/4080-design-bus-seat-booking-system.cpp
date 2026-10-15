class BusBooking {
    vector<array<int,4>> cost;  // cost[row][col]; 0 means not booked
    int total = 0, cnt = 0;
public:
    BusBooking(int n) : cost(n + 1, array<int,4>{0,0,0,0}) {}

    void toggle(string seat) {
        int c = seat[0] - 'A';
        int r = stoi(seat.substr(1));

        if (cost[r][c]) {                 // already booked -> free it
            total -= cost[r][c];
            cost[r][c] = 0;
            cnt--;
        } else {                          // book it
            int w = 1;
            if (c == 0 && cost[r][1]) w = 3;      // A with B booked
            else if (c == 3 && cost[r][2]) w = 3; // D with C booked
            cost[r][c] = w;
            total += w;
            cnt++;
        }
    }

    int getTotalTime() { return total; }
    int getMinTime()   { return cnt; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */