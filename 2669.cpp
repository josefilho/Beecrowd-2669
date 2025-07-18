#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// Definindo o tipo para números complexos
using cd = complex<double>;
const double PI = acos(-1.0);

// --- Implementação da FFT ---
// Baseada em implementações padrão (ex: Competitive Programming 3, e-maxx)
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    // Permutação bit-reversal (ordena os elementos para o cálculo in-place)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    // Loop principal da FFT (butterfly operations)
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang)); // Raiz da unidade
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen; // Próxima raiz da unidade
            }
        }
    }

    // Normalização para FFT inversa
    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}

// Função para multiplicar dois polinômios representados por vetores de coeficientes
vector<long long> multiply(const vector<long long>& a_coeffs, const vector<long long>& b_coeffs) {
    vector<cd> fa(a_coeffs.begin(), a_coeffs.end());
    vector<cd> fb(b_coeffs.begin(), b_coeffs.end());

    // Determina o tamanho necessário para a FFT (potência de 2 >= grau resultante + 1)
    int n = 1;
    int max_degree_a = 0;
    for(int i = 0; i < a_coeffs.size(); ++i) if(a_coeffs[i] > 0) max_degree_a = i;
    int max_degree_b = 0;
    for(int i = 0; i < b_coeffs.size(); ++i) if(b_coeffs[i] > 0) max_degree_b = i;

    while (n < max_degree_a + max_degree_b + 1) {
         n <<= 1;
    }

    fa.resize(n);
    fb.resize(n);

    // Aplica a FFT
    fft(fa, false);
    fft(fb, false);

    // Multiplica no domínio da frequência
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];

    // Aplica a FFT inversa
    fft(fa, true);

    // Extrai os coeficientes resultantes (arredondando para o inteiro mais próximo)
    vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real()); // Pega a parte real e arredonda

    // Remove zeros finais desnecessários se houver, mas mantenha o tamanho pelo menos max_degree_a + max_degree_b + 1
    int actual_degree = max_degree_a + max_degree_b;
     while (result.size() > actual_degree + 1 && result.back() == 0) {
         result.pop_back();
     }
     // Garante que o tamanho é suficiente para acessar os índices que precisamos
     if (result.size() <= actual_degree) {
         result.resize(actual_degree + 1, 0);
     }


    return result;
}

// --- Lógica Principal ---
int main(int argc, char** argv) {
    // Redireciona a entrada e saída se um arquivo for fornecido como argumento
    
    if(argc > 1) {
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    // Otimização da E/S em C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Lê a linha inteira, pois `cin >> s` pararia no primeiro espaço
    // e pode ser lento para 10^5 caracteres. getline é mais robusto aqui.
    getline(cin, s);
    int n = s.length();

    // Calcula os pesos prefixos
    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') { // Verifica se é uma letra minúscula
             p[i + 1] = p[i] + (s[i] - 'a' + 1);
        } else {
            // Tratar caso inválido se necessário, ou assumir entrada correta
            cerr << "Caractere inválido encontrado: " << s[i] << endl;
            return 1; // Ou outra forma de erro
        }
    }
    long long mu_s = p[n]; // Peso total da string s

    // Prepara os vetores de coeficientes para os polinômios P_s e Q_s
    // O grau máximo do resultado é 2 * mu_s. O tamanho do vetor para FFT
    // precisa ser uma potência de 2 maior ou igual a 2*mu_s + 1.
    long long max_possible_degree = 2 * mu_s;
    int fft_vec_size = 1;
    while (fft_vec_size <= max_possible_degree) {
        fft_vec_size <<= 1;
    }

    vector<long long> poly_P_coeffs(fft_vec_size, 0);
    vector<long long> poly_Q_coeffs(fft_vec_size, 0);

    // Constrói P_s(x): Coeficiente 1 na posição p_i para i de 1 a n
    for (int i = 1; i <= n; ++i) {
        if (p[i] < poly_P_coeffs.size()) { // Checa limite do vetor
            poly_P_coeffs[p[i]] = 1;
        } else {
            cerr << "Erro: Índice p[i] fora dos limites!" << endl; return 1;
        }
    }

    // Constrói Q_s(x): Coeficiente 1 na posição mu_s - p_i para i de 0 a n-1
    for (int i = 0; i < n; ++i) {
        long long index = mu_s - p[i];
        if (index >= 0 && index < poly_Q_coeffs.size()) { // Checa limite do vetor
        poly_Q_coeffs[index] = 1;
        } else {
        cerr << "Erro: Índice mu_s - p[i] fora dos limites!" << endl; return 1;
        }
    }


    // Multiplica os polinômios usando FFT
    vector<long long> poly_C_coeffs = multiply(poly_P_coeffs, poly_Q_coeffs);

    // Conta os pesos distintos
    // Um peso M existe se o coeficiente c_{M + mu_s} > 0
    int distinct_weights_count = 0;
    // Iteramos de M=1 até mu_s (peso máximo possível de uma subcadeia)
    // O índice correspondente em C(x) é m = M + mu_s
    // Então m varia de mu_s + 1 até 2*mu_s
    for (long long m = mu_s + 1; m <= max_possible_degree; ++m) {
        // Verifica se o índice m é válido no vetor resultante
        if (m < poly_C_coeffs.size() && poly_C_coeffs[m] > 0) {
            distinct_weights_count++;
        }
    }

    cout << distinct_weights_count << endl;

    return 0;
}