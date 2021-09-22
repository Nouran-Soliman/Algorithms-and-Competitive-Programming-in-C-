#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;

class genetic_row{

	public:
	int chromes[5];
	int x;
	int fitness;
	float current_offspring;
	int actual_offspring;

	void set_genes(int a, int b, int c, int d, int e){
		chromes[4] = a;
		chromes[3] = b;
		chromes[2] = c;
		chromes[1] = d;
		chromes[0] = e;
	}

	void set_x(){
		int pow = 1;
		int val = 0;
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < i; j++)
				pow *= 2;
			val += (pow * chromes[i]);
			pow = 1;
		}
		x = val;
	}

	void set_fitness(){
		fitness = x * x;
	}
	void set_offspring(float average){
		current_offspring = fitness / average;
		actual_offspring = round(current_offspring);
	}
};

float get_avrg(genetic_row prob[4]){
	float avrg = 0;
	for(int i = 0; i < 4; i ++)
		avrg += prob[i].fitness;

	return avrg/4;
}

void set_input(genetic_row *prob){
	prob[0].set_genes(0, 1, 1, 0, 1);
	prob[1].set_genes(1, 1, 0, 0, 0);
	prob[2].set_genes(0, 1, 0, 0, 0);
	prob[3].set_genes(1, 0, 0, 1, 1);
	int avrg = get_avrg(prob);

	for(int i = 0; i < 4; i++){
		prob[i].set_x();
		prob[i].set_fitness();
		prob[i].set_offspring(293);
	}
}

void crossover(genetic_row *prob){

	for(int i = 0; i < 4; i++){
		if(!prob[i].actual_offspring) continue;
		for(int j = 0; j < 4; j++){
			if(i == j) continue;
			if(prob[j].actual_offspring){
				cout << i << " " << j << endl;
				int swp1 = prob[i].chromes[3];
				int swp2 = prob[i].chromes[4];

				prob[i].chromes[3] = prob[j].chromes[3];
				prob[i].chromes[4] = prob[j].chromes[4];

				prob[j].chromes[3] = swp1;
				prob[j].chromes[4] = swp2;

				i = max(i, j);
			}
		}
	}
}

void mutate(genetic_row *prob){
	int zero = 0;
	int done = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 4; j >= 0; j--){
			if(!prob[i].chromes[j] && zero < 3 && !done){
				prob[i].chromes[j] = 1;
				zero++;
				done = 1;
			}
			else if(zero == 3 && prob[i].chromes[j] && !done){
				prob[i].chromes[j] = 0;
				done = 1;
			}
		}
		done = 0;
	}

}

void print(genetic_row *prob){
	for(int i = 0; i < 4; i++){
		for(int j = 4; j >= 0; j--)
			cout << prob[i].chromes[j];
		cout << " " << prob[i].x;
		cout << " " << prob[i].fitness;
		cout << " " << prob[i].current_offspring;
		cout << " " << prob[i].actual_offspring;
		cout << endl;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);	//input file
		//freopen("in.out","w",stdout);	//output file

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	genetic_row prob[4];
	set_input(prob);
	int flag = 0;
	int it = 0;
	for(int i = 0; i < 4; i++)
		if(prob[i].actual_offspring == 0) flag ++;
	while(flag < 3 && it < 5){
		print(prob);
		crossover(prob);
		mutate(prob);
		for(int i = 0; i < 4; i++){
			prob[i].set_x();
			prob[i].set_fitness();
		}
		int avrg = get_avrg(prob);
		for(int i = 0; i < 4; i++)
			prob[i].set_offspring(avrg);

		flag = 0;
		for(int i = 0; i < 4; i++)
			if(prob[i].actual_offspring == 0) flag ++;
		it++;
	}
	printf("done!");
	//mutate(prob);
	//crossover(prob);
	//print(prob);
}
