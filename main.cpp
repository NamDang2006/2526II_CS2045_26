#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

std::string loan_decision(int age, double income, int credit_score, char employment) {
    if (age < 18 || age > 65) {
        return "Invalid Input";
    }
        
    double income_rounded = std::round(income * 10.0) / 10.0;
    if (income_rounded < 5.0 || income_rounded > 500.0) {
        return "Invalid Input";
    }
        
    if (credit_score < 300 || credit_score > 850) {
        return "Invalid Input";
    }
        
    if (employment != 'C' && employment != 'F') {
        return "Invalid Input";
    }

    std::string risk;
    if (credit_score >= 300 && credit_score <= 500) {
        risk = "High";
    } else if (credit_score >= 501 && credit_score <= 700) {
        risk = "Medium";
    } else {
        risk = "Low";
    }

    if (risk == "High") {
        return "REJECT";
    }
        
    if (income_rounded < 15.0) {
        if (employment == 'F' || risk == "Medium") {
            return "REJECT";
        } else if (employment == 'C' && risk == "Low") {
            return "MANUAL REVIEW";
        }
    }
    else {
        if (risk == "Low" || risk == "Medium") {
            if (employment == 'C') {
                return "APPROVE";
            } else if (employment == 'F') {
                return "MANUAL REVIEW";
            }
        }
    }
                
    return "REJECT";
}

struct TestCase {
    std::string id;
    int age;
    double income;
    int credit_score;
    char employment;
    std::string expected;
};

int main() {
    std::vector<TestCase> test_cases = {
        {"TC_INV_01", 17, 50.0, 750, 'C', "Invalid Input"},
        {"TC_INV_02", 66, 50.0, 750, 'C', "Invalid Input"},
        {"TC_INV_03", 30, 4.9, 750, 'C', "Invalid Input"},
        {"TC_INV_04", 30, 500.1, 750, 'C', "Invalid Input"},
        {"TC_INV_05", 30, 50.0, 299, 'C', "Invalid Input"},
        {"TC_INV_06", 30, 50.0, 851, 'C', "Invalid Input"},
        {"TC_INV_07", 30, 50.0, 750, 'X', "Invalid Input"},
        {"TC_VAL_01", 30, 10.0, 300, 'C', "REJECT"},
        {"TC_VAL_02", 30, 20.0, 500, 'F', "REJECT"},
        {"TC_VAL_03", 30, 5.0, 501, 'C', "REJECT"},
        {"TC_VAL_04", 30, 14.9, 700, 'F', "REJECT"},
        {"TC_VAL_05", 30, 10.0, 701, 'C', "MANUAL REVIEW"},
        {"TC_VAL_06", 30, 10.0, 850, 'F', "REJECT"},
        {"TC_VAL_07", 18, 15.0, 600, 'C', "APPROVE"},
        {"TC_VAL_08", 65, 500.0, 800, 'C', "APPROVE"},
        {"TC_VAL_09", 30, 100.0, 650, 'F', "MANUAL REVIEW"},
        {"TC_VAL_10", 30, 100.0, 750, 'F', "MANUAL REVIEW"}
    };

    int passed_count = 0;
    
    std::cout << std::left << std::setw(12) << "Test ID" << " | "
              << std::setw(25) << "Inputs (A, I, CS, E)" << " | "
              << std::setw(15) << "Expected" << " | "
              << std::setw(15) << "Actual" << " | "
              << "Status" << std::endl;
    std::cout << std::string(82, '-') << std::endl;
    
    for (const auto& tc : test_cases) {
        std::string actual = loan_decision(tc.age, tc.income, tc.credit_score, tc.employment);
        bool is_passed = (actual == tc.expected);
        
        if (is_passed) {
            passed_count++;
        }
        
        std::string inputs_str = "(" + std::to_string(tc.age) + ", " 
                               + std::to_string(tc.income).substr(0, 4) + ", " 
                               + std::to_string(tc.credit_score) + ", '" 
                               + tc.employment + "')";
                               
        std::cout << std::left << std::setw(12) << tc.id << " | "
                  << std::setw(25) << inputs_str << " | "
                  << std::setw(15) << tc.expected << " | "
                  << std::setw(15) << actual << " | "
                  << (is_passed ? "PASSED [OK]" : "FAILED [X]") << std::endl;
    }
    
    std::cout << std::string(82, '-') << std::endl;
    std::cout << "KET QUA KIEU THU: Da pass " << passed_count << "/" << test_cases.size() << " test cases." << std::endl;
    
    return 0;
}
