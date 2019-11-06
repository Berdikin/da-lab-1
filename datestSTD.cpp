#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <chrono>
#include <vector>
using namespace std;

const int SIZE_ARRAY = 1000000; //данная глобальная константа понадобится нам в будущем

//стандартный вектор от Ильвохина. Примечание: почистить от ненужного
/*template <typename T>
class TVector {
public:
    using value_type = T;
    using iterator = value_type*;
    using const_iterator = const value_type*;

    TVector():
        already_used_(0), storage_size_(0), storage_(nullptr)
    {
    }

    TVector(int size, const value_type& default_value = value_type()):
        TVector()
    {
        assert(size >= 0);

        if (size == 0)
            return;

        already_used_ = size;
        storage_size_ = size;
        storage_ = new value_type[size];

        fill(storage_, storage_ + already_used_, default_value);
    }

    int Size() const
    {
        return already_used_;
    }

    /*bool empty() const
    {
        return Size() == 0;
    }

    iterator begin() const
    {
        return storage_;
    }

    iterator end() const
    {
        if (storage_)
            return storage_ + already_used_;

        return nullptr;
    }

    friend void Swap(TVector& lhs, TVector& rhs)
    {
        using std::swap;

        swap(lhs.already_used_, rhs.already_used_);
        swap(lhs.storage_size_, rhs.storage_size_);
        swap(lhs.storage_, rhs.storage_);
    }

    TVector& operator=(TVector other)
    {
        Swap(*this, other);
        return *this;
    }

    TVector(const TVector& other):
        TVector()
    {
        TVector next(other.storage_size_);
        next.already_used_ = other.already_used_;

        if (other.storage_ )
            copy(other.storage_, other.storage_ + other.storage_size_,
                      next.storage_);

        Swap(*this, next);
    }

    ~TVector()
    {
        delete[] storage_;

        storage_size_ = 0;
        already_used_ = 0;
        storage_ = nullptr;
    }

    void PushBack(const value_type& value)
    {
        if (already_used_ < storage_size_) {
            storage_[already_used_] = value;
            ++already_used_;
            return;
        }

        int next_size = 1;
        if (storage_size_)
            next_size = storage_size_ * 2;

        TVector next(next_size);
        next.already_used_ = already_used_;

        if (storage_ )
            std::copy(storage_, storage_ + storage_size_, next.storage_);

        next.PushBack(value);
        Swap(*this, next);
    }

    const value_type& At(int TInsex) const
    {
        if (TInsex < 0 || TInsex > already_used_)
            throw std::out_of_range("You are doing this wrong!");

        return storage_[TInsex];
    }

    value_type& At(int TInsex)
    {
        const value_type& elem = const_cast<const TVector*>(this)-> At(TInsex);
        return const_cast<value_type&>(elem);
    }

    const value_type& operator[](int TInsex) const
    {
        return At(TInsex);
    }

    value_type& operator[](int TInsex)
    {
        return At(TInsex);
    }

private:
    int already_used_;
    int storage_size_;
    value_type* storage_;
};*/

typedef unsigned long long long_t;

class TInsex{
public:
    long_t key, elem;
    TInsex(int k, long_t e) : key(k), elem(e) {}
    TInsex() : key(), elem() {}
    friend TInsex* CountingSort(TInsex* obj, long_t max, size_t n);
    void Show(){
      cout << setw(6) << setfill('0') << key << "    " << elem << '\n';
    }
    TInsex Set(long_t k, long_t e){
      elem = e;
      key  = k;
      return *this;
    }
  };

/*void CountingSort(vector <unsigned long long>& a){     //каунтинг сорт. передаем вектор по ссылке, чтобы его менять в самой функции и мэйне.
  int *c = new int[SIZE_ARRAY]{0};    // создаем вспомогательный массив и заполняем его нулями
  vector <unsigned long long> out(a.size());  // это вектор размером с входной для промежуточной записи отсортированного

  for (size_t i = 0; i < a.size(); ++i){     //считаем элементы
    c[a[i].key]++;
    //c[a[i].key] = a[i].elem;
  }
  for (int i = 1; i < SIZE_ARRAY; ++i){
    c[i] += c[i - 1];
  }
  for (int i = a.size() - 1; i >= 0; i--){     // ставим в промежуточный массив с конца все из исходного вектора (всё с лекции)
    out[--c[a[i].key]] = a[i];
  }
  Swap(out, a);         //Меняем местами содержимое а и аут, чтобы в массиве а был ответ (все изменится в мэйне сразу)
  delete[] c;    //удаляем массив с счетчиком.
}*/

void KGen(long long& outkey)
{
    outkey = rand() % 1000000;
    
}

int main(void){
    ios::sync_with_stdio(false); //включаем рассинхрoнизацию потоков, это существенно ускоряет программу
    long_t e, k = 0;
    //vector <TInsex> a;
    //TInsex tmp;   //это мы заполняем ниже, копируем в вектор и заново заполняем
    long long tmp;
    srand(time(NULL));
    vector <long long> lines;

    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        KGen(tmp);
        lines.push_back(tmp);
    }
    /*while (scanf("%llu%llu", &k, &e) == 2) {     // не знаю, почему, но scanf работает быстрее. Возможно, это связано с тем, что cin и cout должны синхронизироваться со страндартной библиотекой Си
      tmp.Set(k, e);
      a.push_back(tmp);     //суем в вектор
    }

    
    /*for (int i = 0; i < a.size(); i++){
      //a[i].Show();
      cout << a.begin() << "    " << a.end();
    }*/
    auto begin = std::chrono::steady_clock::now();
      std::sort(lines.begin(), lines.end());  //сортируем и а сразу сортируется в то же а
      auto end = std::chrono::steady_clock::now();
  
  auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    return 0; // все ок)
}