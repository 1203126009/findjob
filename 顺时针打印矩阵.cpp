class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) {
            return matrix[0];
        }
        int row = matrix.size() ;
        int column =matrix[0].size();
        int start = 0;
        vector<int> result;
        //result.clear();//可以不写
         
        while (column > start*2 && row > start*2) {
            int endX = column - 1 - start;
            int endY = row - 1 - start;
            //从左到右打印一行
            for (int i=start; i<=endX; i++) {
                result.push_back(matrix[start][i]);
            }
            //从上到下打印一行
            if (start <endY) {
                for (int i=start+1; i<=endY; i++) {
                    result.push_back(matrix[i][endX]);
                }
            }
            //从右到左打印一行
            if (start < endX && start < endY) {
                for (int i=endX-1; i>=start; i--) {
                    result.push_back(matrix[endY][i]);
                }
            }
            //从下到上打印一行
            if (start<endX && start<endY-1) {
                for (int i=endY-1; i>=start+1; i--) {
                    result.push_back(matrix[i][start]);
                }
            }
            start++;
        }
        return result;
    }
};



//改剑指offer接口
class Solution2 {
	vector <int >res;//保存结果
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		
		int rows = matrix.size();
		int columns = matrix[0].size();
		//复制到二维数组
		int** numbers = new int*[rows];
		for (int i = 0; i < rows; ++i)
		{
			numbers[i] = new int[columns];
			for (int j = 0; j < columns; ++j)
			{
				numbers[i][j] = matrix[i][j];
			}
		}
		PrintMatrixClockwisely(numbers, columns, rows);

		//释放内存
		for (int i = 0; i < rows; ++i)
			delete[](int*)numbers[i];
		delete[] numbers;
        return res;
	}

		void PrintMatrixClockwisely(int** numbers, int columns, int rows)
		{
			if (numbers == nullptr || columns <= 0 || rows <= 0)
				return;

			int start = 0;

			while (columns > start * 2 && rows > start * 2)
			{
				PrintMatrixInCircle(numbers, columns, rows, start);

				++start;
			}
		}

		void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
		{
			int endX = columns - 1 - start;
			int endY = rows - 1 - start;

			// 从左到右打印一行
			for (int i = start; i <= endX; ++i)
			{
				int number = numbers[start][i];
				res.push_back(number);
			}

			// 从上到下打印一列
			if (start < endY)
			{
				for (int i = start + 1; i <= endY; ++i)
				{
					int number = numbers[i][endX];
					res.push_back(number);
				}
			}

			// 从右到左打印一行
			if (start < endX && start < endY)
			{
				for (int i = endX - 1; i >= start; --i)
				{
					int number = numbers[endY][i];
					res.push_back(number);
				}
			}

			// 从下到上打印一行
			if (start < endX && start < endY - 1)
			{
				for (int i = endY - 1; i >= start + 1; --i)
				{
					int number = numbers[i][start];
					res.push_back(number);
				}
			}
		}

};


