#include <iostream>

int main()
{
    unsigned date_one_day;
    unsigned date_one_month;
    unsigned date_one_year;
    
    std::cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
    std::cin >> date_one_day;
    std::cout << "Bitte geben Sie den Monat des ersten Datums ein: ";
    std::cin >> date_one_month;
    std::cout << "Bitte geben Sie das Jahr des ersten Datums ein: ";
    std::cin >> date_one_year;
    
    unsigned date_two_day;
    unsigned date_two_month;
    unsigned date_two_year;
    
    std::cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
    std::cin >> date_two_day;
    std::cout << "Bitte geben Sie den Monat des zweiten Datums ein: ";
    std::cin >> date_two_month;
    std::cout << "Bitte geben Sie das Jahr des zweiten Datums ein: ";
    std::cin >> date_two_year;
    
    int diff_days = date_one_day - date_two_day;
    int diff_months = date_one_month - date_two_month;
    int diff_years = date_one_year - date_two_year;
    
    if (!diff_days && !diff_months && !diff_years)
    {
        std::cout << "Beide Datumsangaben sind gleich." << std::endl;
    }
    else if (diff_years > 0 || 
             (diff_years == 0 && diff_months > 0) || 
             (diff_years == 0 && diff_months == 0 && diff_days > 0))
    {
        std::cout << "Das zweite Datum liegt vor dem ersten Datum." << std::endl;
    }
    else if (diff_years < 0 || 
             (diff_years == 0 && diff_months < 0) || 
             (diff_years == 0 && diff_months == 0 && diff_days < 0))
    {
        std::cout << "Das erste Datum liegt vor dem zweiten Datum." << std::endl;
    }
    return 0;
}
