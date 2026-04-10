class Worker:
    def __init__(self, worker_num, fname, lname,
                 work_experience_company, salary, age):
        self.worker_num = worker_num
        self.fname = fname
        self.lname = lname
        self.work_experience_company = work_experience_company
        self.salary = salary
        self.age = age

    def worker_information(self):
        print(self.worker_num, self.fname, self.lname, self.work_experience_company,
              self.salary, self.age)

    def salary_bonus(self):
        if 5<= self.work_experience_company <= 10:
            self.salary *= 1.015
        elif self.work_experience_company > 10:
            self.salary *= 1.02
        elif self.work_experience_company < 5:
            self.salary *= 1.005

while True:
    try:
        n = int(input())
        if n > 0:
            break
        else:
            print()
    except ValueError:
        print()

worker_list = []
for i in range(n):
    worker_num = int(input())
    fname = input()
    lname = input()
    work_experience_company = int(input())
    salary = float(input())
    age = int(input())
    item = Worker(worker_num, fname, lname, work_experience_company, salary, age)
    worker_list.append(item)

def search_by_num(worker_list, num):
    for i in worker_list:
        if i.worker_num == num:
            return True
    return False

def search_by_name_experience(worker_list, fname, experience):
    result = [i for i in worker_list if (i.fname) == fname and i.work_experience_company == experience]
    return result

def add_worker(worker_list, worker):
    worker_list.append(worker)

def remove_worker(worker_list, worker_num):
    for worker in worker_list:
        if worker.worker_num == worker_num:
            worker_list.remove(worker)
            print("Information deleted !!!")
            return
    print("Wrong worker_num !!!")