#pragma once
#include "Vision/AbstractImageAnalyzer.h"

#include "Common/AsstBattleDef.h"

namespace asst
{
    class RoguelikeRecruitSupportAnalyzer final : public AbstractImageAnalyzer
    {
    public:
        using AbstractImageAnalyzer::AbstractImageAnalyzer;
        virtual ~RoguelikeRecruitSupportAnalyzer() noexcept override = default;

        bool analyze() override;

        void set_mode(RoguelikeSupportAnalyzeMode mode) noexcept { m_mode = mode; }
        void set_required(std::vector<std::string> required) noexcept { m_required = required; }

        const auto& get_result_choose_support() { return m_choose_support_result; }
        const auto& get_result_char() { return m_char_result; }
        const auto& get_result_refresh() { return m_refresh_result; }

    private:
        RoguelikeSupportAnalyzeMode m_mode;
        Rect m_choose_support_result;
        RoguelikeRefreshSupportInfo m_refresh_result;
        std::vector<RoguelikeRecruitSupportCharInfo> m_char_result;
        std::vector<std::string> m_required;

        int judge_is_friend(const Rect& roi, const double r_threshold);
        int match_elite(const Rect& roi, const int threshold);
        int match_level(const Rect& roi);
    };
}