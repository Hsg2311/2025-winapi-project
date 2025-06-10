#ifndef __IMAGE_STORAGE_HPP__
#define __IMAGE_STORAGE_HPP__

#include "PointFloat.hpp"
#include "Object.hpp"
#include <map>
#include <string>
#include <vector>

struct statdata {
    int speedstat;
    int jumpstat;
    int kickstat;
};

class ImageStorage : public Object
{
public:
    ImageStorage() : Object(), index_(0), flagIndex_(0), statIndex_(0) {
        initializeImages();
    }
    ImageStorage(const std::string_view name) : Object(name), index_(0), flagIndex_(0), statIndex_(0) {
        initializeImages();
    }
    ImageStorage(const ImageStorage&) = delete;
    ImageStorage& operator=(const ImageStorage&) = delete;
    ImageStorage(ImageStorage&&) = delete;
    ImageStorage& operator=(ImageStorage&&) = delete;
    virtual ~ImageStorage() = default;

    void update() override;
    void render(HDC hdc) override;

    void addImage(const std::string& key, Image* image) {
        images_[key] = image;
    }
    void addFlagImage(const std::string& key, Image* image) {
        flagImages_[key] = image;
    }
    void addStatImage(const std::string& key, Image* image) {
        stats_[key] = image;
    }
    Image* getImage(const std::string& key) {
        return images_[key];
    }
    Image* getFlagImage(const std::string& key) {
        return flagImages_[key];
    }
    Image* getStatImage(const std::string& key) {
        return stats_[key];
    }
    std::int32_t getIndex() const { return index_; }
    std::int32_t getFlagIndex() const { return flagIndex_; }
    std::int32_t getStatIndex() const { return statIndex_; }
    void setIndex(std::int32_t index) { index_ = (index % 4 + 4) % 4; }
    void setFlagIndex(std::int32_t flagIndex) { flagIndex_ = (flagIndex % 4 + 4) % 4; }
    void setStatIndex(std::int32_t statIndex) { statIndex_ = (statIndex % 4 + 4) % 4; }
    void updateIndices(std::int32_t delta) {
        setIndex(index_ + delta);
        setFlagIndex(flagIndex_ + delta);
        setStatIndex(statIndex_ + delta);
		allstatindex = (statIndex_ + 4) % 4;
    }
    void setimagepos(PointFloat charpos, PointFloat flagpos, PointFloat statpos) {
        charpos_ = charpos;
        flagpos_ = flagpos;
        statpos_ = statpos;
    }
    int getspeed() {
        return statData[statIndex_].speedstat;
    }
    int getjump() {
        return statData[statIndex_].jumpstat;
    }
    int getkick() {
        return statData[statIndex_].kickstat;
    }

private:
    void initializeImages();
    PointFloat charpos_;
    PointFloat flagpos_;
    PointFloat statpos_;
    std::vector<statdata> statData; // �ʱ�ȭ�� cpp����
    std::map<std::string, Image*> images_;    // ĳ���� �̹���
    std::map<std::string, Image*> flagImages_; // ���� �̹���
    std::map<std::string, Image*> stats_;      // ���� ������
    std::int32_t index_;
    std::int32_t flagIndex_;
    std::int32_t statIndex_;
    std::int32_t allstatindex;
};

#endif // __IMAGE_STORAGE_HPP__