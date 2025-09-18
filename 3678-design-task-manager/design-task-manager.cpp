class TaskManager
{
public:
    set<pair<int, int>> priority_task;
    unordered_map<int, int> task_priority;
    unordered_map<int, int> task_user;
    TaskManager(vector<vector<int>> &tasks)
    {

        for (int i = 0; i < tasks.size(); i++)
        {
            int user = tasks[i][0];
            int task = tasks[i][1];
            int priority = tasks[i][2];
            priority_task.insert({-1 * priority, -1 * task});
            task_priority[task] = priority;
            task_user[task] = user;
        }
    }

    void add(int userId, int taskId, int priority)
    {
        priority_task.insert({-1 * priority, -1 * taskId});
        task_priority[taskId] = priority;
        task_user[taskId] = userId;
    }

    void edit(int taskId, int newPriority)
    {
        int old_priority = task_priority[taskId];
        old_priority *= -1;
        priority_task.erase({old_priority, taskId * -1});
        priority_task.insert({newPriority * -1, taskId * -1});
        task_priority[taskId] = newPriority;
    }

    void rmv(int taskId)
    {
        int prior = task_priority[taskId];
        priority_task.erase({prior * -1, taskId * -1});
        task_priority.erase(taskId);
        task_user.erase(taskId);
    }

    int execTop()
    {   if(task_user.empty()) return -1;
        auto temp = *priority_task.begin();
        priority_task.erase(temp);
        int taskid = temp.second * -1;
        int priorityId = temp.first * -1;
        task_priority.erase(taskid);
        int userid = task_user[taskid];
        task_user.erase(taskid);
        return userid;
    }
};
