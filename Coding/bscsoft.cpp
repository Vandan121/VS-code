#include<bits/stdc++.h>
#include <math.h>
#include <chrono>
#include <cstddef>
#include <cstring>
#include <cassert>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif

class Tanner_graph
{
private:
	const int data_num, check_num;
	std::vector<int>* data_nodes;
	std::vector<int>* check_nodes;

	//no copy
	Tanner_graph(const Tanner_graph& graph);
	Tanner_graph& operator =(const Tanner_graph& graph);
public:
	Tanner_graph(int _data_num, int _check_num) :
		data_num(_data_num),
		check_num(_check_num),
		data_nodes(new std::vector<int>[data_num]),
		check_nodes(new std::vector<int>[check_num])
	{
	}
	~Tanner_graph(){
		delete[] data_nodes;
		delete[] check_nodes;
	}
	//insert an duplex edge between data node and check node. 
	void insert_duplex_edge(int data_id, int check_id)
	{
		data_nodes[data_id].push_back(check_id);
		check_nodes[check_id].push_back(data_id);
	}
	//get the data node given node index
	std::vector<int>& get_data_node(int id)
	{
		return data_nodes[id];
	}
	//get the check node given node index
	std::vector<int>& get_check_node(int id)
	{
		return check_nodes[id];
	}
	int get_code_len() const{ return data_num; }
	int get_check_len() const{ return check_num; }
};
#ifndef __BIT_ARRAY_H
#define __BIT_ARRAY_H

#define __BIT_ARRAY_CHECK


#if 0
class simple_bit_array_t{
private:
	int len;
	bool* buffer;
	simple_bit_array_t(int _len, bool* _buffer) :len(_len), buffer(_buffer){}
public:
	simple_bit_array_t() :len(0), buffer(NULL){}
	simple_bit_array_t(int _len) :len(_len), buffer(new bool[_len]){}
	~simple_bit_array_t(){
		if (buffer != NULL)delete[] buffer; buffer = NULL;
	}
	simple_bit_array_t(simple_bit_array_t& arr){
		this->len = arr.len;
		this->buffer = new bool[len];
		memcpy(buffer, arr.buffer, sizeof(bool)*len);
	}
	simple_bit_array_t(bool* arr, int _len) :len(_len), buffer(new bool[_len]){
		memcpy(buffer, arr, sizeof(bool)*len);
	}
	int size() const{ return len; }
	simple_bit_array_t& operator=(const simple_bit_array_t& arr){
		this->len = arr.len;
		if (this->buffer != NULL)delete[] this->buffer;
		this->buffer = new bool[len];
		memcpy(buffer, arr.buffer, sizeof(bool)*len);
		return *this;
	}
	void clear(bool value = false){
		if (!value)memset(buffer, 0, sizeof(bool)*(len));
		else memset(buffer, true, sizeof(bool)*(len));
	}
	inline bool get(int index) const{
		return buffer[index];
	}
	simple_bit_array_t operator |(const simple_bit_array_t& arr){
		simple_bit_array_t res(len);
		for (int i = 0; i < len; i++)
			res.buffer[i] = arr.buffer[i] | buffer[i];
		return res;
	}

	simple_bit_array_t operator ^(const simple_bit_array_t& arr){
		simple_bit_array_t res(len);
		for (int i = 0; i < len; i++)
			res.buffer[i] = arr.buffer[i] ^ buffer[i];
		return res;
	}
	simple_bit_array_t operator &(const simple_bit_array_t& arr){
		simple_bit_array_t res(len);
		for (int i = 0; i < len; i++)
			res.buffer[i] = arr.buffer[i] & buffer[i];
		return res;
	}
	simple_bit_array_t operator !(){
		simple_bit_array_t res(len);
		for (int i = 0; i < len; i++)
			res.buffer[i] = !buffer[i];
		return res;
	}

	simple_bit_array_t& operator |=(const simple_bit_array_t& arr){
		for (int i = 0; i < len; i++)
			buffer[i] |= arr.buffer[i];
		return *this;
	}

	simple_bit_array_t& operator &=(const simple_bit_array_t& arr){
		for (int i = 0; i < len; i++)
			buffer[i] &= arr.buffer[i];
		return *this;
	}
	simple_bit_array_t& operator ^=(const simple_bit_array_t& arr){
		for (int i = 0; i < len; i++)
			buffer[i] ^= arr.buffer[i];
		return *this;
	}
	inline void set(int index, bool val){
		buffer[index] = val;
	}
	inline void xor(int index, bool val){
		buffer[index] ^= val;
	}
	inline bool operator [](int id) const{
		return get(id);
	}
};
typedef simple_bit_array_t bit_array_t;

#else
class bit_array_t{
private:
	typedef char uint8_t;
	int len;
	char* buffer;
	bit_array_t(int _len, char* _buffer) :len(_len), buffer(_buffer){}
public:
	bit_array_t() :len(0), buffer(NULL){}
	bit_array_t(int _len) :len(_len), buffer(new char[(_len + 7) / 8]){}
	~bit_array_t(){ if (buffer != NULL)delete[] buffer; buffer = NULL; }
	bit_array_t(bit_array_t& arr){
		this->len = arr.len;
		this->buffer = new char[(len + 7) / 8];
		memcpy(buffer, arr.buffer, sizeof(char)*((len + 7) / 8));
	}
	bit_array_t(bool* arr, int _len) :len(_len), buffer(new char[(_len + 7) / 8]){
		for (int i = 0; i < len; i++)
			set(i, arr[i]);
	}
	int size() const{ return len; }
	bit_array_t& operator=(const bit_array_t& arr){
		this->len = arr.len;
		if (this->buffer != NULL)delete[] this->buffer;
		this->buffer = new char[(len + 7) / 8];
		memcpy(buffer, arr.buffer, sizeof(char)*((len + 7) / 8));
		return *this;
	}
	void clear(bool value = false){
		if (!value)memset(buffer, 0, sizeof(char)*((len + 7) / 8));
		else memset(buffer, 255, sizeof(char)*((len + 7) / 8));
	}
	inline bool get(int index) const{
#ifdef __BIT_ARRAY_CHECK
		assert(index < len);
#endif
		return (buffer[index / 8] >> (index % 8)) & 1;
	}
	bit_array_t operator |(const bit_array_t& arr){
		assert(arr.len == len);
		bit_array_t res(len);
		for (int i = 0; i < (len + 7) / 8; i++)
			res.buffer[i] = arr.buffer[i] | buffer[i];
		return res;
	}

	bit_array_t operator ^(const bit_array_t& arr){
		assert(arr.len == len);
		bit_array_t res(len);
		for (int i = 0; i < (len + 7) / 8; i++)
			res.buffer[i] = arr.buffer[i] ^ buffer[i];
		return res;
	}
	bit_array_t operator &(const bit_array_t& arr){
		assert(arr.len == len);
		bit_array_t res(len);
		for (int i = 0; i < (len + 7) / 8; i++)
			res.buffer[i] = arr.buffer[i] & buffer[i];
		return res;
	}
	bit_array_t operator !(){
		bit_array_t res(len);
		for (int i = 0; i < (len + 7) / 8; i++)
			res.buffer[i] = !buffer[i];
		return res;
	}

	bit_array_t& operator |=(const bit_array_t& arr){
		for (int i = 0; i < (len + 7) / 8; i++)
			buffer[i] |= arr.buffer[i];
		return *this;
	}

	bit_array_t& operator &=(const bit_array_t& arr){
		for (int i = 0; i < (len + 7) / 8; i++)
			buffer[i] &= arr.buffer[i];
		return *this;
	}
	bit_array_t& operator ^=(const bit_array_t& arr){
		for (int i = 0; i < (len + 7) / 8; i++)
			buffer[i] ^= arr.buffer[i];
		return *this;
	}
	inline void set(int index, bool val){
#ifdef __BIT_ARRAY_CHECK
		assert(index < len);
#endif
		if (val)
			buffer[index / 8] |= (char)(1 << (index % 8));
		else
			buffer[index / 8] &= (char)~(1 << (index % 8));
	}
	inline void xor(int index, bool val){
#ifdef __BIT_ARRAY_CHECK
		assert(index < len);
#endif
		if (val)
			buffer[index / 8] ^= (char)(1 << (index % 8));
	}
	inline bool operator [](int id) const{
		return get(id);
	}
};
#endif
#endif
class binary_matrix
{
private:
	int w;
	int h;
	bit_array_t* bit_array;
public:
	binary_matrix(int _w, int _h) :
		w(_w), h(_h),
		bit_array(new bit_array_t[_h])
		{
		for (int i = 0; i < h; i++){
			bit_array[i] = bit_array_t(w);
			bit_array[i].clear(false);
		}
	}
	~binary_matrix()
	{
		delete[] bit_array;
	}
	bit_array_t& operator [](int j) const
	{
		return bit_array[j];
	}
	inline int width() const
	{ 
	    return w;
	}
	inline int height() const
	{ 
	    return h; 
	    
	}
};
class LDPC_generator
{
public:
	enum GENERATOR_PROPERTY{
		INVALID = 0,
		VALID=1,
		WR_REGULAR = 3,
		WC_REGULAR = 5,
		REGULAR = 7,
		UPPER_TRIANGLE = 57,
		PSEUDO_UPPER_TRIANGLE = 41,
		FULL_RANK = 33,
		GIRTH_6 = 65
	};
	virtual GENERATOR_PROPERTY init(int code_len, int msg_len) = 0;
	virtual std::unique_ptr<Tanner_graph> as_Tanner_graph() = 0;
	virtual std::unique_ptr<binary_matrix> as_binary_matrix() = 0;
	bool save_to_plist(const char* filename);
};


class LDPC_bp_decoder
{
private:
	int code_len;
	int msg_len;

	double* messages;
	int** check_to_data;
	int* check_to_data_mem;
	int* check_degree;
	int** data_to_check;
	int* data_to_check_mem;
	int* data_degree;
	int** check_to_data_id;
	int* check_to_data_id_mem;

	bool* msg_sign;

	double* data_nodes;
	double* error;

public:
	LDPC_bp_decoder(int code_len, int msg_len);
	~LDPC_bp_decoder();

	//init by a given generated parity check matrix
	bool init(LDPC_generator* generator);
	//init by a buffered sparse graph
	bool init(const char* filename);
	//check if a code is valid
	bool check(const bit_array_t& data);
	//soft-decision decoder for BSC
	bool decode_BSC(bit_array_t& data, double error_prob, int iterations=50);
	//hard-decision decoder for BEC
	bool decode_BEC(bit_array_t& data, bit_array_t& mask);
	//hard-decision decoder for generalized BEC
	
	template<typename T>
	bool decode_BEC(T* arr, bit_array_t& mask){
		//first: initialize
		bool found = false;
		bool no_erasure = false;

		do{
			found = false;
			no_erasure = true;
			for (int i = 0; i < code_len - msg_len; i++){
				auto check_node = check_to_data_id[i];
				int erasure_count = 0;
				int erasure_id = 0;
				T other_xor;
				for (int j = 0; j < check_degree[i]; j++){
					if (!mask[check_node[j]]){
						erasure_count++;
						erasure_id = check_node[j];
					}
					else other_xor ^= arr[check_node[j]];
				}
				if (erasure_count > 0)
					no_erasure = false;
				if (erasure_count == 1){
					arr[erasure_id] = other_xor;
					mask.set(erasure_id, true);
					found = true;
				}
			}
		} while (found&&!no_erasure);
		return no_erasure;
	}
	//soft-decision decoder for BSC, given all symbol's belief
	bool decode_BSC(bit_array_t& result, const double* data_prob, int iterations=50);
	//hard-decision decoder for BSC
	bool decode_BSC(bit_array_t& data, int iterations = 50);
};




static unique_ptr<binary_matrix> to_binary_matrix(const unique_ptr<Tanner_graph>& graph, int code_len, int msg_len)
{
	std::unique_ptr<binary_matrix> res(new binary_matrix(code_len, code_len - msg_len));
	for (int i = 0; i < code_len - msg_len; i++){
		auto& row = res->operator[](i);
		auto list = graph->get_check_node(i);
		for (auto it : list)
			row.set(it, true);
	}
	return res;
}
static std::unique_ptr<Tanner_graph> to_Tanner_graph(const std::unique_ptr<binary_matrix> mat, int code_len, int msg_len)
{
	int h = code_len - msg_len;
	std::unique_ptr<Tanner_graph> res;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < code_len; j++)
			if (mat->operator[](i)[j])
				res->insert_duplex_edge(j, i);
	return res;
}

//generating parity check matrix/Tanner graph

//read from an existing plist file
class LDPC_plist_generator : public LDPC_generator
{
private:
	int code_len, msg_len;
	char* const filename;
public:
	LDPC_plist_generator(const char* filename);
	~LDPC_plist_generator()
	{ 
	    if (filename) 
	    delete[] filename; 
	    
	}
	virtual GENERATOR_PROPERTY init(int code_len, int msg_len);
	virtual std::unique_ptr<Tanner_graph> as_Tanner_graph();
	virtual std::unique_ptr<binary_matrix> as_binary_matrix();
};
class LDPC_Gallager_generator :public LDPC_generator
{
private:
	int code_len, msg_len;
	const int Wr, Wc;
	const int seed;
	const bool check_cycle;

	std::unique_ptr<Tanner_graph> wocycle_as_Tanner_graph();
	std::unique_ptr<binary_matrix> wcycle_as_binary_matrix();
public:
	LDPC_Gallager_generator(int Wr, int Wc, int seed, bool _check_cycle);
	virtual GENERATOR_PROPERTY init(int code_len, int msg_len);
	virtual std::unique_ptr<Tanner_graph> as_Tanner_graph();
	virtual std::unique_ptr<binary_matrix> as_binary_matrix();
};

//quasi-cyclic code
class LDPC_QuasiCyclic_generator:public LDPC_generator
{
private:
	int code_len,msg_len;
	const int Wr,Wc;
	const int seed;
public:
	LDPC_QuasiCyclic_generator(int Wr,int Wc,int seed);
	virtual GENERATOR_PROPERTY init(int code_len,int msg_len);
	virtual std::unique_ptr<Tanner_graph> as_Tanner_graph();
	virtual std::unique_ptr<binary_matrix> as_binary_matrix();
};

//array code
class LDPC_array_generator :public LDPC_generator
{
private:
	int code_len, msg_len;
	const int Wr, Wc;
	const bool upper_tri;
public:
	LDPC_array_generator(int Wr, int Wc, bool upper_tri);
	virtual GENERATOR_PROPERTY init(int code_len, int msg_len);
	virtual std::unique_ptr<Tanner_graph> as_Tanner_graph();
	virtual std::unique_ptr<binary_matrix> as_binary_matrix();
};


bool LDPC_bp_decoder::init(const char* filename)
{
	FILE* fp;
	fopen_s(&fp, filename, "rt");
	int m;
	fscanf_s(fp, "%d%d", &code_len, &m);
	msg_len = code_len - m;
	
	//unused
	int cmax, rmax;
	fscanf_s(fp, "%d%d", &cmax, &rmax);

	check_degree = new int[code_len - msg_len];
	data_degree = new int[code_len];

	int* col_weight = new int[code_len+1];
	col_weight[0] = 0;
	for (int i = 0; i < code_len; i++) 
	{
		fscanf_s(fp, "%d", &data_degree[i]);
		col_weight[i + 1] = col_weight[i] + data_degree[i];
	}
	int* row_weight = new int[m + 1];
	row_weight[0] = 0;
	for (int j = 0; j < m; j++)
	{
		fscanf_s(fp, "%d", &check_degree[j]);
		row_weight[j + 1] = row_weight[j] + check_degree[j];
	}
	
	assert(col_weight[code_len] == row_weight[m]);
	int total = col_weight[code_len];

	check_to_data = new int*[code_len - msg_len];
	check_to_data_mem = new int[total];

	data_to_check = new int*[code_len];
	data_to_check_mem = new int[total];

	msg_sign = new bool[code_len];

	messages = new double[total];

	check_to_data_id_mem = new int[total];
	check_to_data_id = new int*[code_len - msg_len];

	data_nodes = new double[code_len];
	error = new double[code_len];

	int** data_to_check_id = new int*[code_len];
	int* data_to_check_id_mem = new int[total];

	for (int i = 0; i < code_len; i++)
	{
		data_to_check[i] = data_to_check_mem + col_weight[i];
		data_to_check_id[i] = data_to_check_id_mem + col_weight[i];
		data_degree[i] = col_weight[i + 1] - col_weight[i];
		int j;
		for (j = 0; j < data_degree[i]; j++)
		{
			data_to_check[i][j] = col_weight[i] + j;
			fscanf_s(fp, "%d", &(data_to_check_id[i][j]));
			data_to_check_id[i][j]--;
		}

		for (; j < cmax; j++)
		{
			fscanf_s(fp, "%*d"); // skip the 0s (fillers)
		}
	}

	check_to_data[0] = check_to_data_mem;
	check_to_data_id[0] = check_to_data_id_mem;
	for (int i = 0; i < m; i++)
	{
		check_to_data[i] = check_to_data_mem + row_weight[i];
		check_to_data_id[i] = check_to_data_id_mem + row_weight[i];

		check_degree[i] = row_weight[i + 1] - row_weight[i];
		int j;
		for (j = 0; j < check_degree[i]; j++)
		{
			fscanf_s(fp, "%d", &(check_to_data_id[i][j]));
			check_to_data_id[i][j]--;
			auto& n2 = data_to_check_id[check_to_data_id[i][j]];
			int id = std::find(n2, n2+data_degree[check_to_data_id[i][j]], i) - n2;
			check_to_data[i][j] = data_to_check[check_to_data_id[i][j]][id];
		}

		for (; j < rmax; j++)
		{
			fscanf_s(fp, "%*d"); // skip the 0s (fillers)
		}
	}

	delete[] data_to_check_id;
	delete[] data_to_check_id_mem;
	return true;
}

static inline double LLR(double d)
{
	return log(d / (1 - d));
}
bool LDPC_bp_decoder::check(const bit_array_t& data)
{
	for (int i = 0; i < code_len - msg_len; i++){
		auto check_node = check_to_data_id[i];
		bool res = false;
		for (int j = 0; j < check_degree[i]; j++)
			res ^= data[check_node[j]];
		if (res)return false;
	}
	return true;
}

bool LDPC_bp_decoder::decode_BSC(bit_array_t& data, double error_prob, int iterations)
{
	for (int i = 0; i < code_len; i++)error[i] = data[i] ? (1 - error_prob) : error_prob;
	bool result = decode_BSC(data, error, iterations);
	return result;
}

bool LDPC_bp_decoder::decode_BEC(bit_array_t& data, bit_array_t& mask)
{
	//first: initialize
	bool found = false;
	bool no_erasure = false;

	do{
		found = false;
		no_erasure = true;
		for (int i = 0; i < code_len - msg_len; i++){
			auto check_node = check_to_data_id[i];
			int erasure_count = 0;
			int erasure_id = 0;
			bool other_xor = false;
			for (int j = 0; j < check_degree[i];j++){
				if (!mask[check_node[j]]){
					erasure_count++;
					erasure_id = check_node[j];
				}
				else other_xor ^= data[check_node[j]];
			}
			if (erasure_count > 0)
				no_erasure = false;
			if (erasure_count == 1){
				data.set(erasure_id, other_xor);
				mask.set(erasure_id, true);
				found = true;
			}
		}
	} while (found&&!no_erasure);
	return no_erasure;
}

//just for test
static void print_bitarr(const bit_array_t& src)
{
	for (int i = 0; i < src.size(); i++)
		printf(src[i] ? "1" : "0");
	printf("\n");
}

inline double atanh2(double f)
{
	return log((1 + f) / (1 - f));
}
inline double trunc_atanh(double f)
{
	if (-0.9999 < f && f < 0.9999)return atanh(f);
	else if (f < -0.9999)return -5;
	else return 5;
}
bool LDPC_bp_decoder::decode_BSC(bit_array_t& result, const double* data_prob, int iterations)
{
	//first: initialze
	for (int i = 0; i < code_len; i++){
		data_nodes[i] = LLR(data_prob[i]);
		auto data_node = data_to_check[i];
		for (int j = 0; j < data_degree[i]; j++)
			messages[data_node[j]] = data_nodes[i];
	}
	//second: bp
	for (int iter = 0; iter < iterations; iter++){
		int m = code_len - msg_len;
		for (int i = 0; i < m; i++){
			double total_msg = 0.0;
			bool sign = false;
			auto check_node = check_to_data[i];
			for (int j = 0; j < check_degree[i];j++){
				double t = tanh(messages[check_node[j]]*0.5);
				messages[check_node[j]] = log(fabs(t));
				msg_sign[j] = t >= 0;
				sign ^= msg_sign[j];
				total_msg += messages[check_node[j]];
			}
			for (int j = 0; j < check_degree[i];j++){
				messages[check_node[j]] = -atanh2(exp(total_msg - messages[check_node[j]])*((sign^msg_sign[j]) ? -1 : 1));
			}
		}
		
		for (int i = 0; i < code_len; i++){
			double total_LLR = data_nodes[i];
			auto data_node = data_to_check[i];
			for (int j = 0; j < data_degree[i];j++){
				total_LLR += messages[data_node[j]];
			}
			
			for (int j = 0; j < data_degree[i];j++){
				messages[data_node[j]] = total_LLR - messages[data_node[j]];
			}

			result.set(i, total_LLR>=0);
		}
		//check
		if (check(result)){
			return true;
		}
	}

	return false;
}
bool LDPC_bp_decoder::decode_BSC(bit_array_t& data, int iterations){
	//first: initialze
	bool* data_nodes_bin = (bool*)data_nodes;
	bool* messages_bin = (bool*)messages;

	for (int i = 0; i < code_len; i++){
		data_nodes_bin[i] = data[i];
		auto data_node = data_to_check[i];
		for (int j = 0; j < data_degree[i];j++)
			messages_bin[data_node[j]] = data_nodes_bin[i];
	}
	//second: bp
	for (int iter = 0; iter < iterations; iter++){
		for (int i = 0; i < code_len - msg_len; i++){
			bool msg_sum = false;
			auto check_node = check_to_data[i];
			for (int j = 0; j < check_degree[i]; j++){
				msg_sum ^= messages_bin[check_node[j]];
			}
			for (int j = 0; j < check_degree[i]; j++){
				messages_bin[check_node[j]] = msg_sum^messages_bin[check_node[j]];
			}
		}
		for (int i = 0; i < code_len; i++){
			auto data_node = data_to_check[i];
			int pos = 0, neg = 0;
			for (int j = 0; j < data_degree[i];j++){
				if (messages_bin[data_node[j]])pos++;
				else neg++;
			}

			int t = pos - neg + (data_nodes_bin[i] ? 1 : -1);
			for (int j = 0; j < data_degree[i];j++){
				int tt = messages_bin[data_node[j]] ? (t - 1) : (t + 1);
				messages_bin[data_node[j]] = (tt == 0) ? data_nodes_bin[i] : (tt > 0);
			}
			data.set(i, t == 0 ? data_nodes_bin[i] : t > 0);
		}
		//check
		if (check(data)){
			return true;
		}
	}

	return false;
}