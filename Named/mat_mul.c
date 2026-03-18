void MatMul(const double Mat1[2][2], const double Mat2[2][2], double ResMat[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ResMat[i][j] = 0; 
            for (int k = 0; k < 2; k++) {
                ResMat[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}