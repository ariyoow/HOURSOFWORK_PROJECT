// Author : arian

#include <iostream>

using namespace std;
//.............................................................................................................................

#define max_working_days 30

//............................................................................................................................

/// @brief This function is for reading the start and end times of the work.
/// @param ary1 This ary is for reading the date of working days.
/// @param ary2 This ary is for reading the time of start.
/// @param ary3 This ary is for reading the time of finish.
/// @param n This variable is for the number of days that person should have worked.
void read_time_date(int ary1[], int ary2[], int ary3[], int n);

/// @brief This function is used to calculate how much a person works every day.
/// @param ary1 This ary is for reading the time of start.
/// @param ary2 This ary is for reading the time of finish.
/// @param ary3 This ary is for printing the difference between start and finish.
/// @param n This variable is for the number of days that person should have worked.
void difference_arrays(int ary1[], int ary2[], int ary3[], int n);

/// @brief This function is used to give the usual start and finish time.
/// @param ary This ary is for reading the time of start or finish.
/// @param n This variable is for the number of days that person should have worked.
/// @return The usual start and finish time.
int usual_time(int ary[], int n);

/// @brief This function is used to give the average working hours.
/// @param ary1 This ary is for reading the time of difference between start and finish.
/// @param n This variable is for the number of days that person should have worked.
int total_time(int ary[], int n);

/// @brief Tis function iis used to give total hours of work deduction.
/// @param ary This ary is for reading the difference between start and finish.
/// @param x This variable is for the duty minutes .
/// @param n This variable is for the number of days that person should have worked.
/// @return Total hours of work deduction
int work_deduction(int ary[], int x, int n);

/// @brief Tis function iis used to give total hours of overtime.
/// @param ary This ary is for reading the difference between start and finish.
/// @param x This variable is for the duty minutes .
/// @param n This variable is for the number of days that person should have worked.
/// @return Total hours of overtime
int overtime(int ary[], int x, int n);

/// @brief This function is used to give the sum of delays and unjustified delays.
/// @param ary1 This ary is for reading the time of start.
/// @param ary2 This ary is for reading the difference between start and finish.
/// @param ary3 This ary is for printing sum of sum of delays and unjustified delays.
/// @param x This varible is for offical start time.
/// @param y This variable is for the duty hours.
/// @param z This variable is for reasonable deceleration per working hour.
/// @param n This variable is for the number of days that person should have worked.
void unjustified_deceleration(int ary1[], int ary2[], int ary3[], int x, int y, int z, int n);

/// @brief This function is used to give the sum of unwarranted haste
/// @param ary1  This ary is for reading the time of finish.
/// @param ary2 This ary is for reading the difference between start and finish.
/// @param ary3 This ary is for printing sum of haste and unwarranted haste
/// @param x This varible is for offical finish time.
/// @param y This variable is for the duty hours.
/// @param z This variable is for reasonable acceleration per working hour.
/// @param n This variable is for the number of days that person should have worked.
void unjustified_acceleration(int ary1[], int ary2[], int ary3[], int x, int y, int z, int n);

/// @brief This function is used to give maximum working hours and their dates.
/// @param ary1 This ary is for reading the difference between start and finish.
/// @param ary2 This ary is for reading the date of working days
/// @param ary3 This ary is for printing  maximum of working hours and that dates.
/// @param n This variable is for the number of days that person should have worked.
void max_hours_work(int ary1[], int ary2[], int ary3[], int n);

/// @brief This function is used to give minimum working hours and their dates.
/// @param ary1 This ary is for reading the difference between start and finish.
/// @param ary2 This ary is for reading the date of working days
/// @param ary3 This ary is for printing  minimum of working hours and that dates.
/// @param n This variable is for the number of days that person should have worked.
void min_hours_work(int ary1[], int ary2[], int ary3[], int n);

//.............................................................................................................................
// 24-Hour format

int main()

{
    int start_ary[max_working_days], finish_ary[max_working_days], date_ary[max_working_days], difference_ary[max_working_days], max_ary[4], min_ary[4], delay_ary[2], haste_ary[2];

    int work_days;
    cout << "\nEnter Work day: ";
    cin >> work_days;

    int duty_hours;
    cout << "\nEnter Duty hour: ";
    cin >> duty_hours;
    int duty_mintues = duty_hours * 60;

    int H1, M1;
    cout << "\nEnter official start time. hour and minute: ";
    cin >> H1 >> M1;

    int H2, M2;
    cout << "\nEnter official finish time. hour and minute: ";
    cin >> H2 >> M2;

    M1 = H1 * 60 + M1;
    M2 = H2 * 60 + M2;

    int irregular_hours;
    cout << "\nEnter reasonable acceleration or deceleration in minute: ";
    cin >> irregular_hours;

    read_time_date(date_ary, start_ary, finish_ary, work_days);
    difference_arrays(start_ary, finish_ary, difference_ary, work_days);
    unjustified_deceleration(start_ary, difference_ary, delay_ary, M1, duty_mintues, irregular_hours, work_days);
    unjustified_acceleration(finish_ary, difference_ary, haste_ary, M2, duty_mintues, irregular_hours, work_days);
    max_hours_work(difference_ary, date_ary, max_ary, work_days);
    min_hours_work(difference_ary, date_ary, min_ary, work_days);

    cout << "\nThe usual starting time  is :\t" << usual_time(start_ary, work_days) / 60 << "hours\t" << usual_time(start_ary, work_days) % 60 << "minutes";
    cout << "\nThe usual finishing time is :\t" << usual_time(finish_ary, work_days) / 60 << "hours\t" << usual_time(finish_ary, work_days) % 60 << "minutes";
    cout << "\nThe total working time is :\t" << total_time(difference_ary, work_days) / 60 << "hours\t" << total_time(difference_ary, work_days) % 60 << "minutes";

    cout << "\nThe average working time per day is :\t" << (total_time(difference_ary, work_days) / work_days) / 60 << "hours\t" << (total_time(difference_ary, work_days) / work_days) % 60 << "minutes";
    cout << "\nThe Total hours of work deduction is :\t " << work_deduction(difference_ary, duty_mintues, work_days) / 60 << "hours" << work_deduction(difference_ary, duty_mintues, work_days) % 60 << "minutes";
    cout << "\nThe Total hours of overtime is :\t " << overtime(difference_ary, duty_mintues, work_days) / 60 << "hours" << overtime(difference_ary, duty_mintues, work_days) % 60 << "minutes";

    cout << "\nTotal authorized delay in starting work is :\t " << (delay_ary[0] - delay_ary[1]) / 60 << "hours\t" << (delay_ary[0] - delay_ary[1]) % 60 << "minutes";
    cout << "\nTotal unauthorized delay in starting work is :\t" << delay_ary[1] / 60 << "hours\t" << delay_ary[1] % 60 << "minutes";
    cout << "\nTotal authorized haste at end of work is :\t " << (haste_ary[0] - haste_ary[1]) / 60 << "hours\t" << (haste_ary[0] - haste_ary[1]) % 60 << "minutes";
    cout << "\nTotal unauthorized haste at end of work is :\t" << haste_ary[1] / 60 << "hours\t" << haste_ary[1] % 60 << "minutes";

    cout << "\nThe Most working hours is :\t" << max_ary[0] / 60 << "hours\t" << max_ary[0] % 60 << "minutes\t"
         << "And that date is :\t" << max_ary[1] << "/" << max_ary[2] << "/" << max_ary[3];
    cout << "\nThe Least working hours is :\t" << min_ary[0] / 60 << "hours\t" << min_ary[0] % 60 << "minutes\t"
         << "And that date is :\t" << min_ary[1] << "/" << min_ary[2] << "/" << min_ary[3];

    return 0;
}

//..............................................................................................................................

void read_time_date(int ary1[], int ary2[], int ary3[], int n)
{
    int Y, M, D, h1, h2, m1, m2;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter new date.\n Year , Month , Day :";
        cin >> Y >> M >> D;
        ary1[i] = Y * 10000 + M * 100 + D;
        cout << "\nEnter new start time.\n hour , minute :";
        // if he did not go to work, enter  0 and 0;
        cin >> h1 >> m1;

        ary2[i] = h1 * 60 + m1;

        if (h1 != 0 || m1 != 0)
        {
            cout << "\nEnter new end time.\n hour , minute :";
            cin >> h2 >> m2;
            ary3[i] = h2 * 60 + m2;
        }
        else
            ary3[i] = 0;
    }

    /*
     for(int i = 0; i < n; i++)
    {
        cout << ary1[i] << "\t" << ary2[i] << "\t" << ary3[i] << "\t" ;
    }
    */
}

void difference_arrays(int ary1[], int ary2[], int ary3[], int n)
{
    for (int i = 0; i < n; i++)
        ary3[i] = ary2[i] - ary1[i];

    //    for (int i = 0; i < n; i++)
    //      cout << ary3[i] << "\t";
}

int usual_time(int ary[], int n)
{
    int sum = 0, count = 0;

    for (int i = 0; i < n; i++)
        if (ary[i] != 0)
        {
            sum += ary[i];
            count += 1;
        }

    return (sum / count);
}

int total_time(int ary[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += ary[i];

    return sum;
}

int work_deduction(int ary[], int x, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        if (ary[i] < x)
            sum += (x - ary[i]);

    return sum;
}

int overtime(int ary[], int x, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        if (ary[i] > x)
            sum += (ary[i] - x);

    return sum;
}

void unjustified_deceleration(int ary1[], int ary2[], int ary3[], int x, int y, int z, int n)
{
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++)
        if ((ary1[i] - x) > 0)
            sum1 += (ary1[i] - x);
    ary3[0] = sum1;

    for (int i = 0; i < n; i++)
    {
        if (ary2[i] == 0)
            continue;

        if (ary2[i] >= y)
        {
            if ((ary1[i] - x) > z)
                sum2 += (ary1[i] - x);
        }
        else
            sum2 += (ary1[i] - x);
    }
    ary3[1] = sum2;
}

void unjustified_acceleration(int ary1[], int ary2[], int ary3[], int x, int y, int z, int n)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (ary1[i] == 0)
            continue;

        if ((x - ary1[i]) > 0)
            sum1 += (x - ary1[i]);
    }
    ary3[0] = sum1;

    for (int i = 0; i < n; i++)
    {
        if (ary1[i] == 0)
            continue;
            
        if (ary2[i] >= y)
        {
            if ((x - ary1[i]) > z)
                sum2 += (x - ary1[i]);
        }
        else
            sum2 += (x - ary1[i]);
    }
    ary3[1] = sum2;
}

void max_hours_work(int ary1[], int ary2[], int ary3[], int n)
{
    int max = ary1[0], f;

    for (int i = 0; i < n; i++)
        if (ary1[i] > max)
        {
            max = ary1[i];

            f = i;
        }

    ary3[0] = max;
    ary3[1] = ary2[f] / 10000;
    ary3[2] = (ary2[f] % 10000) / 100;
    ary3[3] = ary2[f] % 100;
}

void min_hours_work(int ary1[], int ary2[], int ary3[], int n)
{
    int min = ary1[0], f;

    for (int i = 0; i < n; i++)
        if (ary1[i] < min)
        {
            min = ary1[i];

            f = i;
        }

    ary3[0] = min;
    ary3[1] = ary2[f] / 10000;
    ary3[2] = (ary2[f] % 10000) / 100;
    ary3[3] = ary2[f] % 100;
}