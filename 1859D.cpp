// this code is a solve for a problem 1859D on codeforces (Andrey and Escape from Capygrad)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 
int segment_of_x (int x,  vector <int> &segments_l, vector <int> &segments_b){
  int h = segments_b.size()-1;
  int l = 0;
  int m = l + (h - l) / 2;
	while (l <= h) {
		m = l + (h - l) / 2;
 
 
		if (x >= segments_l[m] && x <= segments_b[m])
			return segments_b[m];
 
 
		if (segments_l[m] > x)
      h = m - 1;
		else
			l = m + 1;
	}
 
	return x;

}

void x_engine (vector <int> &segments_l, vector <int> &segments_b){
  vector <int> segments_l_c; 
  vector <int> segments_b_c; 
	int start = segments_l[0];
  int end = segments_b[0];
  for(int i = 1; i < segments_b.size(); i++){
    if(end >= segments_l[i])end = segments_b[i];
    else{
      segments_l_c.push_back(start);
      segments_b_c.push_back(end);
      start = segments_l[i];
      end = segments_b[i];
    }
  } 
  segments_l_c.push_back(start);
  segments_b_c.push_back(end);

  segments_l=segments_l_c;
  segments_b=segments_b_c;
}

void engine (){
  int number_of_segments ;
  cin >> number_of_segments;
  int l,r,a,b;
  vector <int> segments_l;
  vector <int> segments_b;
  for(int i = 0;i < number_of_segments; i++)
  {
    cin >> l >> r >> a >> b;
    segments_l.push_back(l);      //inputting
    segments_b.push_back(b);
  }
  sort(segments_b.begin(),segments_b.end());
  sort(segments_l.begin(),segments_l.end());
  x_engine(segments_l,segments_b);
//////////////////inputting xes
  int number_of_xes ;
  cin >> number_of_xes;
  vector <int> xes;
  int x;
  for(int i = 0 ; i< number_of_xes; i++){
    cin >> x ;
    xes.push_back(x);
  }

  for(int i = 0 ; i< number_of_xes; i++){
    cout << segment_of_x(xes[i],segments_l,segments_b) << " ";
  }
    cout << "\n" ;

}

 
int main() {
  int number_of_cases;
  cin >> number_of_cases;
 
  for (int j = 0; j < number_of_cases; j++){
    engine();
  }
}