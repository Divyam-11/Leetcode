class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    /*
    students =
[1,1,1,0,0,1]
sandwiches =
[1,0,0,0,1,1]
eat = 1


*/
        int able_eat = 0;
        queue<int> students_1;
        stack<int> sandwiches_1;
        for(int i = 0 ; i< students.size();i++){
            students_1.push(students[i]);
            
        }
        for(int i = students.size() - 1;i>=0;i--){
            sandwiches_1.push(sandwiches[i]);
        }
        int eat = 0;
        int last_pick = 0;
        while(!sandwiches_1.empty()){
            if(sandwiches_1.top() == students_1.front()){
                sandwiches_1.pop();
                students_1.pop();
                last_pick = 0;
                eat++;
            }
            else if(last_pick == students_1.size()) {
                break;
            }
            else {
                int temp = students_1.front();
                students_1.pop();
                students_1.push(temp);
                last_pick ++;
            }
        }
    return students_1.size();
    }
};