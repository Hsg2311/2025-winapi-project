#ifndef __CHARACTER_INFO_HPP__
#define __CHARACTER_INFO_HPP__

#include <string>
class CharacterInfo
{
public:
	
	std::string getImage() const { return imageName; }
	std::string getFlag() const { return flagName; }
	int getScore() const { return score; }
	int getSpeedStat() const { return speedStat_; }
	int getJumpStat() const { return jumpStat_; }
	int getKickStat() const { return kickStat_; }
	
	void setImagename(const std::string& img) { imageName = img; }
	void setFlagname(const std::string& flg) { flagName = flg; }
	void setScore(int scr) { score = scr; }
	void setStats(int speed, int jump, int kick) {
		speedStat_ = speed;
		jumpStat_ = jump;
		kickStat_ = kick;
	}

private:
	std::string imageName;
	std::string flagName;
	int score;
	int speedStat_;
	int jumpStat_;
	int kickStat_;
};

#endif