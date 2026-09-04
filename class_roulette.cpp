//
// Created by sdias on 29/08/2026.
// Source code for randomly partition students
// Must be compiled with -std=c++23 flag
//
// For reproduction of results, one must set seed to 1266837840
//

#include <algorithm>
#include <random>
#include <array>
#include <cstdio>

constexpr unsigned NUM_STUDENTS = 60;

const std::array<std::tuple<int, std::string>, NUM_STUDENTS> students = {
    std::tuple{2026005874, "ANELISA FERNANDES DOS REIS BENEDICTO"},
    {2026011165, "ARIEL RODRIGUES PEREIRA"},
    {2025019427, "CAUÃ NICOLAU MENDES"},
    {2025016167, "DANIEL DE SENE SILVA"},
    {2026008704, "DANIEL DOS SANTOS SILVA"},
    {2025019857, "DAVI FERREIRA TASE"},
    {2026002219, "DIEGO WALLACE GUEDES DOS SANTOS"},
    {2026008455, "ELISA SILVA CARVALHO"},
    {2026000401, "ENÉAS SPERLE MATHIAS CONDE NETO"},
    {2024002078, "ERIC MOREIRA MACHADO"},
    {2025007159, "FELIPE AUGUSTO SOUZA BARBOSA"},
    {2026003243, "FELIPE CESAR RODRIGUES"},
    {2026002200, "FELIPE DE OLIVEIRA VARGA"},
    {2026005382, "FRANCISCO TEBALDI MIRANDA MORANDI"},
    {2026006307, "GABRIEL CAMPOS BEZERRA PEREIRA"},
    {2026003584, "GABRIEL FERREIRA SANTANA"},
    {2023007276, "GABRIEL HENRIQUE SILVA"},
    {2026002101, "GABRIEL PALOMO RODRIGUES"},
    {2026008473, "GUILHERME GAMA"},
    {2026014443, "GUSTAVO EDUARDO RIBEIRO"},
    {2026012636, "GUSTAVO RODRIGUES MACHADO"},
    {2024016028, "IGOR DINIZ SILVA"},
    {2023008110, "IGOR RAFAEL VIEIRA CORREIA"},
    {2026003440, "ISABELA ROSA DIAS"},
    {2026001463, "ISABELLA RIBEIRO CONTI DE FREITAS"},
    {2026002086, "JOAO AUGUSTO TRAVNISK DE SOUZA SILVA NOBRE"},
    {2026002148, "JOÃO INACIO RAFAEL"},
    {2026007805, "KAUAN TERRABUIO MASSEU"},
    {2025003768, "LUANA CRISTINA VALERIO"},
    {2026007841, "LUANNA RODRIGUES DA SILVA"},
    {2026018550, "LUCAS ANDRADE DE SOUZA"},
    {2025019919, "LUCAS BORGES DE SOUZA"},
    {2026019717, "LUCAS GABRIEL RIBEIRO RAMOS"},
    {2026001481, "LUCAS RAPHAEL MORAES PEREIRA"},
    {2026002175, "LUIGI RICARDO DA SILVA"},
    {2025019196, "LUIZ FILIPE DA SILVA"},
    {2026014640, "LUIZA DA SILVA CHAVES"},
    {2026016063, "MARCELO AGRICO GUEDES"},
    {2025019730, "MARCUS EDUARDO RIBEIRO"},
    {2025013236, "MARIA EDUARDA MAIA SANTOS"},
    {2025009832, "MARIANA XAVIER BRAZ"},
    {2026002237, "MATEUS PRADO COSTA"},
    {2026018040, "MATHEUS HENRIQUE DE CARVALHO"},
    {2026006620, "MATHEUS MATIAS PINTO"},
    {2024011139, "MAURICIO SANTOS DE ARAUJO"},
    {2026002934, "MAXIME KOFFI JUNIOR"},
    {2020017297, "MIKAEL ROCHA BERNARDES"},
    {2026001490, "PEDRO HENRIQUE SILVA"},
    {2026005800, "PEDRO LUCAS PIRES RAIMUNDO"},
    {2025017084, "RAFAEL GONÇALVES PERES"},
    {2025004845, "RAISSA VITORIA BATISTA SILVA"},
    {2026009532, "RAUL OTAVIO RIBEIRO SILVA"},
    {2026016054, "RENAN SERPA GOULART"},
    {2025015375, "Samara Barros Feitosa"},
    {2026007000, "THEO ZULETA DURAES"},
    {2025006788, "THIAGO JOSE DA CRUZ"},
    {2026003771, "THIAGO MEIRELES SILVA"},
    {2026005990, "VITOR JOSE TAGLIAFERRO"},
    {2025011714, "VITOR RIVELI DE SOUZA LOPES"},
    {2021002047, "WELBER HUMBERTO DOMINGOS"}
};

int main()
{
    // Lambda function for printing a vector
    auto printer = [](auto& v)
    {
        for (auto& i : v)
        {
            printf("%4d", i);
        }
        printf("\n");
    };

    // Increasing order indices array
    std::vector students_indices(NUM_STUDENTS, 0);
    std::iota(students_indices.begin(), students_indices.end(), 0);

    // Partition vector: 1 - first day, 2 - second day
    std::vector test_day(NUM_STUDENTS, 0);
    std::fill(test_day.begin(), test_day.begin() + NUM_STUDENTS / 2, 1);
    std::fill(test_day.begin() + NUM_STUDENTS / 2, test_day.end(), 2);

    printer(students_indices);
    printer(test_day);

    // Randomising stuff
    std::random_device rd;
    auto seed = rd();
    seed = 1266837840; // Seed number set randomly at the moment of execution to determine order
    printf("Using seed = %d\n", seed);

    std::mt19937 generator(seed);
    std::ranges::shuffle(students_indices, generator);
    std::ranges::shuffle(test_day, generator);

    printer(students_indices);
    printer(test_day);

    for (const auto& i : students_indices)
    {
        const auto& [mat, name] = students[i];
        printf("[%d] %s (%d): prova dia %s\n",
            i,
            name.c_str(),
            mat,
            (test_day[i] == 1) ? "24/09/2026" : "25/09/2026");
    }
}
