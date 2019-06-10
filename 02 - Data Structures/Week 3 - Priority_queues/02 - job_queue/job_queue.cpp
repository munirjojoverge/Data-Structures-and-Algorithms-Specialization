/*
Munir Jojo - Verge
04 / 17 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 3 - Priority_queues
			02 - job_queue
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <utility>

using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs_optimal2() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
	//std::priority_queue<long long, std::vector<long long>, std::greater<long long> >worker_finish_time;

    vector<long long> worker_finish_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
	  auto min_finish_time = std::min_element(worker_finish_time.begin(), worker_finish_time.end());
	  next_worker = std::distance(worker_finish_time.begin(), min_finish_time);
      
	  assigned_workers_[i] = next_worker;
      start_times_[i] = worker_finish_time[next_worker];
	  worker_finish_time[next_worker] += duration;
    }
  }

  void AssignJobs_optimal() {
	  // TODO: replace this code with a faster algorithm.
	  assigned_workers_.resize(jobs_.size());
	  start_times_.resize(jobs_.size());
	 
	  // Using lambda to compare elements.
	  auto cmp = [](const pair<int, long long> left, const pair<int, long long> right) {
		  
		  if ((left.second) == (right.second)) 
			  return (left.first > right.first);
		  else
		  
			  return ((left.second) > (right.second));
		  
	  };
	  std::priority_queue<pair<int, long long>, vector< pair<int, long long> >, decltype(cmp)> worker_finish_time(cmp);
	  
	  for (int i = 0; i < jobs_.size(); ++i) {
		  int duration = jobs_[i];
		  int next_worker = 0;
		  pair<int, long long> min_worker_finish_time_pair;
		  if (worker_finish_time.size() < num_workers_) {
			  min_worker_finish_time_pair = make_pair(i, 0);
		  }
		  else
		  {
			  min_worker_finish_time_pair = worker_finish_time.top();
			  worker_finish_time.pop();
		  }
		  next_worker = min_worker_finish_time_pair.first;

		  assigned_workers_[i] = next_worker;
		  start_times_[i] = min_worker_finish_time_pair.second;
		  worker_finish_time.push(make_pair(next_worker, (min_worker_finish_time_pair.second + duration)));
	  }
  }


  void AssignJobs() {
	  // TODO: replace this code with a faster algorithm.
	  assigned_workers_.resize(jobs_.size());
	  start_times_.resize(jobs_.size());
	  vector<long long> next_free_time(num_workers_, 0);
	  for (int i = 0; i < jobs_.size(); ++i) {
		  int duration = jobs_[i];
		  int next_worker = 0;
		  for (int j = 0; j < num_workers_; ++j) {
			  if (next_free_time[j] < next_free_time[next_worker])
				  next_worker = j;
		  }
		  assigned_workers_[i] = next_worker;
		  start_times_[i] = next_free_time[next_worker];
		  next_free_time[next_worker] += duration;
	  }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs_optimal();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
