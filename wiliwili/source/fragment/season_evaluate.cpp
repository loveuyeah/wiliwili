//
// Created by fang on 2023/1/16.
//

#include "fragment/season_evaluate.hpp"
#include "view/mpv_core.hpp"

SeasonEvaluate::SeasonEvaluate() {
    this->inflateFromXMLRes("xml/fragment/season_evaluate.xml");

    btnDouban->registerClickAction([this](...) {
        MPVCore::instance().pause();
        brls::Application::getPlatform()->openBrowser(
            "https://search.douban.com/movie/subject_search?search_text=" +
            this->keyword);
        return true;
    });

    btnZhihu->registerClickAction([this](...) {
        MPVCore::instance().pause();
        brls::Application::getPlatform()->openBrowser(
            "https://www.zhihu.com/search?type=content&q=" + this->keyword);
        return true;
    });

    btnBaidu->registerClickAction([this](...) {
        MPVCore::instance().pause();
        brls::Application::getPlatform()->openBrowser(
            "https://www.baidu.com/s?wd=" + this->keyword);
        return true;
    });

    btnBing->registerClickAction([this](...) {
        MPVCore::instance().pause();
        brls::Application::getPlatform()->openBrowser(
            "https://cn.bing.com/search?q=" + this->keyword);
        return true;
    });
}

void SeasonEvaluate::setKeyword(const std::string& value) {
    this->keyword = value;
}

void SeasonEvaluate::setContent(const std::string& value) {
    this->label->setText(value);
}

SeasonEvaluate::~SeasonEvaluate() {
    brls::Logger::debug("Fragment SeasonEvaluate: delete");
}

brls::View* SeasonEvaluate::create() { return new SeasonEvaluate(); }