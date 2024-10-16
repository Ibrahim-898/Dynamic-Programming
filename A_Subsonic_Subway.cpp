#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        
        double v_min = 0.0;  // this is the maximum of the lower bounds
        double v_max = 1e9;  // this is the minimum of the upper bounds (a large number to start with)
        
        for (int i = 1; i <= N; ++i) {
            int A, B;
            cin >> A >> B;
            
            // Calculate the lower bound for this station
            double v_lower = static_cast<double>(i) / B;
            // Calculate the upper bound for this station
            double v_upper = static_cast<double>(i) / A;
            
            // Update the global bounds
            v_min = max(v_min, v_lower);
            v_max = min(v_max, v_upper);
        }
        
        // Check if there's a valid speed that satisfies all conditions
        if (v_min > v_max) {
            cout << "Case #" << t << ": -1" << endl;
        } else {
            cout << fixed << setprecision(6) << "Case #" << t << ": " << v_min << endl;
        }
    }
    
    return 0;
}
