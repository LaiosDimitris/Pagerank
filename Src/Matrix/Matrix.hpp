class Matrix
{
public:
    Matrix(int rows, int cols);

   ~Matrix(); 

    int get_rows() const;

    int get_cols() const;

    int* operator[](int index);

private:
    int rows;
    int cols;
    int* arr;
};