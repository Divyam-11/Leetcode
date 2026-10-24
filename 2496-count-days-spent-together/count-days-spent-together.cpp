class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int alice_a_d = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
        int alice_a_m = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
        int alice_l_d = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');
        int alice_l_m = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
        int bob_a_d = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
        int bob_a_m = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
        int bob_l_d = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');
        int bob_l_m = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
        int alice_a = ((alice_a_m - 2) == -1 ? 0 : prefix[(alice_a_m - 2)]) + alice_a_d;
        int alice_l = ((alice_l_m - 2) == -1 ? 0 : prefix[(alice_l_m - 2)]) + alice_l_d;
        int bob_a = ((bob_a_m - 2) == -1 ? 0 : prefix[(bob_a_m - 2)]) + bob_a_d;
        int bob_l = ((bob_l_m - 2) == -1 ? 0 : prefix[(bob_l_m - 2)]) + bob_l_d;

        int res = min(bob_l, alice_l) - max(bob_a, alice_a) + 1;
        return res > 0 ? res : 0;
    };
};