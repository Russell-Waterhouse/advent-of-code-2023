// advent of code day 6


#include <vector>
#include <iostream>
#include <fstream>


class RaceAttempt {
public: 
    unsigned long total_time;
    unsigned long time_held;
    unsigned long distance_travelled;

    RaceAttempt(unsigned long total_race_time, unsigned long time_holding_button){
        total_time = total_race_time;
        time_held = time_holding_button;
        unsigned long time_traveling = total_time - time_held;
        distance_travelled = time_held * time_traveling;
    }
};

class Race {
public: 
    unsigned long total_time;
    std::vector<RaceAttempt> all_possible_attempts;
    std::vector<RaceAttempt> all_winning_attempts;

    Race(unsigned long total_race_time, unsigned long current_record) {
        all_possible_attempts = {};
        all_winning_attempts = {};
        total_time = total_race_time; 
        
        unsigned long i = 0;
        for(i = 0; i <= total_race_time; i++) {
            RaceAttempt attempt = RaceAttempt(total_time, i);
            all_possible_attempts.push_back(attempt);
            if(current_record < attempt.distance_travelled) {
                all_winning_attempts.push_back(attempt);
//                std::cout << "pushing back total time: " << total_time << " And hold time " << i <<  " With distance " << attempt.distance_travelled << std::endl;
            }
        }
    }
};

int main() {
    //sample
    Race race1 = Race(7, 9);
    Race race2 = Race(15, 40);
    Race race3 = Race(30, 200);
    
    std::cout << "1: " << race1.all_winning_attempts.size() << std::endl;
    std::cout << "2: " << race2.all_winning_attempts.size() << std::endl;
    std::cout << "3: " << race3.all_winning_attempts.size() << std::endl;

    //real data
    Race real_race1 = Race(56, 499);
    Race real_race2 = Race(97, 2210);
    Race real_race3 = Race(77, 1097);
    Race real_race4 = Race(93, 1440);

    std::cout << "Part 1 answer: " << 
        real_race1.all_winning_attempts.size() * 
        real_race2.all_winning_attempts.size() * 
        real_race3.all_winning_attempts.size() * 
        real_race4.all_winning_attempts.size() 
        << std::endl;

    //part 2
    Race part2 = Race(56977793, 499221010971440);
    std::cout << "Part 2 answer: " << part2.all_winning_attempts.size() << std::endl;
    return 0;
}
