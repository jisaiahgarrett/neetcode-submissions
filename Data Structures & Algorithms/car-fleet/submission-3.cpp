template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (auto i = 0; i < v.size(); i++) {
        os << v[i];
        if (i < v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

struct Car {
    int position;
    int speed;
};

std::ostream& operator<<(std::ostream& os, const Car &car) {
    os << "{position: " << car.position << ", speed: " << car.speed << "}";
    return os;
}

class Solution {    
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       std::cout << "Before: " << position << std::endl;
    //    auto sorted_position = myQuickSort(position, 0, 0);
    //    std::cout << "After: " << sorted_position << std::endl;
        // Create pairs / structs containing the position and velocity of each car. 
        vector<Car> cars;
        for (auto i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        // Sort the list of cars by position in descending order.
        std::cout << "Before sort: " << cars << std::endl;
        sort(cars.begin(), cars.end(), [](const Car &a, const Car &b){return a.position > b.position;});
        std::cout << "After sort: " << cars << std::endl;
        // Create a stack representing the times that each car will arrive at the target.
        std:stack<float> arrival_times;
        // for each car
        for (auto car : cars) {
        //      calculate the arrival time
            auto arrival_time = 1.0*(target - car.position) / car.speed;
        //      if the arrival time is greater than the top of the stack
            std::cout << arrival_time << std::endl;
            if (arrival_times.empty() || arrival_time > arrival_times.top()) {
        //          push the arrival time on the stack.
                arrival_times.push(arrival_time);
            }
        }
        // return size of stack
        return arrival_times.size();
    }
};
