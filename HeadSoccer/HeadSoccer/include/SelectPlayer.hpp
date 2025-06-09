#include <string>
#include <list>

class Player {
private:
    int currentCharacter; // 현재 선택된 캐릭터 인덱스
    const std::string characters[2] = { "Character1", "Character2" }; // 캐릭터 이름

public:
    Player() : currentCharacter(0) {}

    void nextCharacter() {
        currentCharacter = (currentCharacter + 1) % 2;
    }

    void prevCharacter() {
        currentCharacter = (currentCharacter - 1 + 2) % 2;
    }

    std::string getCurrentCharacter() const {
        return characters[currentCharacter];
    }
};

class SelectPlayer {
private:
    std::list<Player> players;
    std::list<std::pair<float, float>> positions;

public:
    SelectPlayer() {
        players.emplace_back();
        players.emplace_back();
        positions.emplace_back(300.f, 350.f);
        positions.emplace_back(980.f, 350.f);
    }

    void nextAllCharacters() {
        for (auto& player : players) {
            player.nextCharacter();
        }
    }

    void prevAllCharacters() {
        for (auto& player : players) {
            player.prevCharacter();
        }
    }
};
