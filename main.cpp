#include <iostream>
#include <cstdlib>

class Hamster {

public:
    Hamster();
    void Play();
    void Stroke();
    void Feed();
    void Resurrect();
    void Drink();
    void Run_in_wheel();
    void Sleep();

private:

    int food;
    int watter;
    int need_sleep;
    int happy;
    int alive;
};


Hamster::Hamster(): food(0), watter(0), need_sleep(5), happy(5), alive(1){
}
void Hamster::Play() {
    if (alive) {
        if (watter && need_sleep && food) {
            std::cout << "Okay, I'll play with you)" << std::endl;
            --watter;
            --need_sleep;
            --food;
        }else {
            if (!watter)
                std::cout << "I want to drink, without water I will not play with you" << std::endl;
            if (!need_sleep)
                std::cout << "Sry, I need sleep or I will fall asleep on the go" << std::endl;
            if (!food)
                std::cout << "I will not play with you, or you feed me, or I leave home" << std::endl;
        }
    } else std::cout << "Your hamster is dead." << std::endl;

}

void Hamster::Stroke() {
    if (alive) {
        std::cout << "Haha, I feel happier" << std::endl;
        ++happy;
    } else std::cout << "Your hamster is dead." << std::endl;
}

void Hamster::Run_in_wheel()  {
    if (watter && need_sleep && food && happy) {
        std::cout << "Okay, for the sake of my beloved master, I run this stupid wheel" << std::endl;
        --watter;
        --need_sleep;
        --food;
        --happy;
    } else {
        if (!watter)
            std::cout << "I need watter." << std::endl;
        if (!need_sleep)
            std::cout << "I need sleep." << std::endl;
        if (!food)
            std::cout << "I need food." << std::endl;
        if (!happy)
            std::cout << "I am not happy." << std::endl;
    }


}

void Hamster::Feed() {
    if (alive) {
        if (food < 3) {
            std::cout << "Finally, I ate something, my master thought of feeding me!" << std::endl;
            ++food;
        } else {
            if (food == 4) {
                std::cout << "This is the last portion, I don't want to overeat, I will burst soon.";
                ++food;
            } else {
                std::cout << "BOOOOOOM" << std::endl;
                alive = 0;
            }
        }
    } else std::cout << "Your hamster is dead." << std::endl;
}

void Hamster::Resurrect() {
    if (!alive) {
        alive = 1;
        need_sleep = 5;
        watter = 0;
        food = 0;
        happy = 0;
        std::cout << "Satisfied? I exploded, now I am hungry, thirsty and besides, I am very unhappy!" << std::endl;
    }
    else {
        std::cout << "Why resurrect me I'm already alive.";
    }
}

void Hamster::Drink() {
    if (alive) {
        if (watter < 4) {
            std::cout << "Thanks for the water!!!";
            ++watter;
        } else if (watter == 4) {
            std::cout << "If I drink another glass I will explode." << std::endl;
            ++watter;
        } else {
            std::cout << "BOOOOOOOOOM!!!!!";
            alive == 0;
        }
    } else std::cout << "Your hamster is dead." << std::endl;
}

void Hamster::Sleep() {
    if (need_sleep < 6) {
        need_sleep = 10;
        std::cout << "Zzzzz.." << std::endl;
    }
    else
        std::cout << "I don't need sleep." << std::endl;
}




int main() {
    int n_pats = 0, n_acts, ac;
    std::cin >> n_pats >> n_acts;
    Hamster pats[n_pats];
    for (int i = 0; i < n_pats; i++)
        for (int act = 0; act < n_acts; act++) {
            ac = rand() % 7;
            switch(ac)
            {
                case 0:
                    pats[i].Drink();
                    break;
                case 1:
                    pats[i].Feed();
                    break;
                case 2:
                    pats[i].Play();
                    break;
                case 3:
                    pats[i].Resurrect();
                    break;
                case 4:
                    pats[i].Run_in_wheel();
                    break;
                case 5:
                    pats[i].Sleep();
                    break;
                case 6:
                    pats[i].Stroke();
                    break;
                default:
                    std::cout << "Error";
            }

        }

    return 0;
}
