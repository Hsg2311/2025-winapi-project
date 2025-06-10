#include "../include/imageStorage.hpp"
#include "../include/ResourceHandler.hpp"
#include <filesystem>
#include "../include/Camera.hpp"

#include<iostream>

void ImageStorage::initializeImages() {
    std::vector<std::string> image = {
        "korea.png",
        "argentina.png",
        "france.png",
        "america.png"
    };
    std::vector<std::string> flag = {
        "k_flag.png",
        "ag_flag.png",
        "f_flag.png",
        "a_flag.png"
    };
    std::vector<std::string> stat = {
        "stat_color.png",
        "stat_color.png",
        "stat_color.png",
        "stat_color.png"
    };
    for (const auto& file : image) {
        auto filePath = std::filesystem::path("assets/" + file);
        Image* image = ResourceHandler::loadImage(file, std::filesystem::canonical(filePath).string(), true);
        addImage(file, image);
    }
    for (const auto& file : flag) {
        auto flagPath = std::filesystem::path("assets/" + file);
        Image* flagImage = ResourceHandler::loadImage(file, std::filesystem::canonical(flagPath).string(), false);
        addFlagImage(file, flagImage);
    }
    for (const auto& file : stat) {
        auto statPath = std::filesystem::path("assets/" + file);
        Image* statImage = ResourceHandler::loadImage(file, std::filesystem::canonical(statPath).string(), true);
        addStatImage(file, statImage);
    }

    // statData �ʱ�ȭ (america, argentina, france, korea ������ ����)
    statData = {
        {8, 5, 5}, // america
        {5, 5, 8}, // argentina
        {7, 7, 5}, // france
        {6, 6, 6}  // korea
    };
}

void ImageStorage::update() {
    componentUpdate();
}

void ImageStorage::render(HDC hdc) {
    // ĳ���� �̹��� ������
    auto images = std::vector<Image*>(images_.size());
    std::transform(images_.begin(), images_.end(), images.begin(),
        [](const auto& pair) { return pair.second; });

    if (index_ >= 0 && static_cast<size_t>(index_) < images.size()) {
        auto relativePos = charpos_ - Camera::getPos();
        images[index_]->draw(hdc, relativePos);
    }

    // �÷��� �̹��� ������
    auto flagImages = std::vector<Image*>(flagImages_.size());
    std::transform(flagImages_.begin(), flagImages_.end(), flagImages.begin(),
        [](const auto& pair) { return pair.second; });

    if (flagIndex_ >= 0 && static_cast<size_t>(flagIndex_) < flagImages.size()) {
        auto flagPos = flagpos_ - Camera::getPos();
        flagImages[flagIndex_]->draw(hdc, flagPos);
    }

    // ���� �̹��� ������

	auto statimage = ResourceHandler::findImage("stat_color.png"); // ���� UI ������
	if (statimage) {
		auto statPos = statpos_ - Camera::getPos();                            
        statimage->draw(hdc, statPos, statData[index_].speedstat, -30);
		statimage->draw(hdc, statPos, statData[index_].jumpstat, -1);
		statimage->draw(hdc, statPos, statData[index_].kickstat, 27);
	}
    
    componentRender(hdc); // Animator�� Collider ������
}