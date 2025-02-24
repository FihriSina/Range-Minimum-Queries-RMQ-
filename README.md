# Range-Minimum-Queries-RMQ-
Range Minimum Queries (RMQ) for Algorithms and Experimental Analysis


# Comparison of Minimum Value Finding Methods

This project compares the performance of different methods to find the minimum value in an array. It implements four approaches and measures their speed on large datasets:

- **Precompute All**: Precomputes all minimum values and uses them during queries.
- **Blocking**: Processes the array in blocks for efficiency.
- **Sparse Table**: Uses a logarithmic time complexity approach.
- **Precompute None**: Calculates the minimum value directly for each query (brute force).

## Features

- Finds the minimum value in large-scale arrays.
- Measures execution times for performance testing.
- Compares various methods with different data sizes.

## Usage

1. **Clone the project files**:
    ```bash
    git clone https://github.com/FihriSina/Range-Minimum-Queries-RMQ-.git
    cd Range-Minimum-Queries-RMQ-
    ```

2. **Compile the code**:
    ```bash
    gcc -o project project.c -lm
    ```

3. **Run the program**:
    ```bash
    ./project
    ```

4. **Review the results**: The program outputs the minimum value and execution times for each method.

## File Structure

- `project.c`: Source file implementing the methods to find the minimum value.
- `README.md`: Documentation about the project.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

---

You can save this as **README.md** and include it in your GitHub repository.



# Minimum Değer Bulma Yöntemlerinin Karşılaştırması

Bu proje, bir dizide minimum değeri bulmak için farklı yöntemlerin performanslarını karşılaştırır. Proje, dört farklı yöntemi uygular ve büyük veri setleri üzerinde hızlarını ölçer:

- **Precompute All**: Tüm minimum değerleri önceden hesaplar ve sorgular.
- **Blocking**: Diziyi bloklara ayırarak işlem yapar.
- **Sparse Table**: Logaritmik zaman karmaşıklığına sahip bir yöntem.
- **Precompute None**: Her sorgu için minimum değeri doğrudan hesaplar (brute force).

## Özellikler

- Büyük ölçekli diziler üzerinde minimum değeri bulma.
- Performans testleri için çalışma sürelerini ölçme.
- Farklı veri boyutları ve yöntemlerin karşılaştırması.

## Kullanım

1. **Proje dosyalarını klonlayın**:
    ```bash
    git clone https://github.com/FihriSina/Range-Minimum-Queries-RMQ-.git
    cd Range-Minimum-Queries-RMQ-
    ```

2. **Kodu derleyin**:
    ```bash
    gcc -o project project.c -lm
    ```

3. **Programı çalıştırın**:
    ```bash
    ./project
    ```

4. **Sonuçları inceleyin**: Her yöntem için minimum değerin yanı sıra çalışma süreleri çıktıda görüntülenecektir.

## Dosya Yapısı

- `project.c`: Minimum değeri bulmak için yöntemlerin uygulandığı ana kaynak dosyası.
- `README.md`: Proje hakkında bilgi.

## Lisans

Bu proje [MIT Lisansı](https://opensource.org/licenses/MIT) ile lisanslanmıştır.
