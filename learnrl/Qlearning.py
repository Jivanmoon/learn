from json.tool import main
import numpy as np
import pandas as pd
import time

#设置随机种子，使得过程和教程一致
np.random.seed(2)

#距离宝物的距离
N_STATES = 6
#可选的动作
ACTION = ['left', 'right']
#greedy police
EPSILON = 0.9
#learning rate
ALPHA = 0.1
#discount factor
LAMBDA = 0.9
#最大回合数
MAX_EPISODES = 13
#走一步花的时间
FRESH_TIME = 0.3

def build_q_table(n_states, actions):
    table = pd.DataFrame(
        #初始值全为0
        np.zeros((n_states, len(actions))),
        #用动作作为列名字
        columns=actions
    )
    #print(table)
    return table

def choose_action(state, q_table):
    state_action = q_table.iloc[state, :]
    #如果随机数大于EPSILON或者Q表中的当前行的值都为0则随机选取一个动作
    if (np.random.uniform() > EPSILON) or (state_action.all() == 0):
        action_name = np.random.choice(ACTION)
    #否则选取Q表当前行中比较大的数
    else:
        action_name = state_action.idxmax()
    return action_name

def get_env_feedback(S, A):
    if A == 'right':
        if S == N_STATES - 2:
            S_ = 'terminal'
            R = 1
        else:
            S_ = S + 1
            R = 0
    else:
        R = 0
        if S == 0:
            S_ = S
        else:
            S_ = S - 1
    return S_, R

def update_env(S, episode, step_counter):
    env_list = ['-']*(N_STATES - 1) + ['T'] #'-----T'
    if S == 'terminal':
        interaction = 'Episode %s: total steps = %s' % (episode + 1, step_counter)
        print('\r{}'.format(interaction), end = '')
        time.sleep(2)
        print('\r                                ', end='')
    else:
        env_list[S] = 'o'
        interaction = ''.join(env_list)
        print('\r{}'.format(interaction), end = '')
        time.sleep(FRESH_TIME)
    
def Qlearning():
    q_table = build_q_table(N_STATES, ACTION)
    for episode in range(MAX_EPISODES):
        step_counter = 0
        S = 0
        is_terminated = False
        update_env(S, episode, step_counter)
        while not is_terminated:
            A = choose_action(S, q_table)
            S_, R = get_env_feedback(S, A)
            q_predict = q_table.loc[S, A]
            if S_ != 'terminal':
                q_target = R + LAMBDA * q_table.iloc[S_, :].max()
            else:
                q_target = R
                is_terminated = True
            
            q_table.loc[S, A] += ALPHA * (q_target - q_predict)
            S = S_

            update_env(S, episode, step_counter + 1)
            
            step_counter += 1
    return q_table

if __name__ == "__main__":
    q_table = Qlearning()
    print('\r\nQ-table:\n')
    print(q_table)