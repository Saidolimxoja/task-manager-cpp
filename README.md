# TaskManager C++ — README

## Установка зависимостей

Используем WSL

```bash
sudo apt update
sudo apt upgrade -y

sudo apt install -y \
build-essential \
cmake \
git \
pkg-config \
libssl-dev \
zlib1g-dev \
uuid-dev

g++ --version
cmake --version

# Установка Drogon
sudo apt install -y libdrogon-dev
dpkg -l | grep drogon

# Установка MySQL клиентских библиотек
sudo apt install -y libmysqlclient-dev default-libmysqlclient-dev

# Создание проекта
mkdir task-manager-cpp
cd task-manager-cpp
```

⚠️ Если версия libdrogon-dev из репозитория слишком старая, можно установить Drogon из исходников:

```bash
git clone https://github.com/drogonframework/drogon.git
cd drogon
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
```

---

## Сборка проекта

```bash
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=/usr/local/lib/cmake/Drogon
make -j$(nproc)
```

---

## Запуск

```bash
./TaskManager
```
После запуска сервер слушает на http://localhost:8080.
---

## РОУТЫ

```bash
| Путь     | Метод | Описание                         |
| -------- | ----- | -------------------------------- |
| `/`      | GET   | Главная страница                 |
| `/tasks` | GET   | Получение списка задач           |
| `/tasks` | POST  | Создание новой задачи            |
| `/user`  | POST  | Создание пользователя (тестовый) |

```

---

## СТРУКТУРА

```bash
task-manager-cpp/
│
├── CMakeLists.txt
├── config.json
├── docker-compose.yml
│
├── src/
│   ├── main.cc
│   │
│   ├── controllers/
│   │   ├── TaskController.h
│   │   └── UserController.h
│   │
│   ├── services/
│   │   ├── TaskService.h
│   │   └── UserService.h
│   │
│   ├── repositories/
│   │   ├── TaskRepository.h
│   │   └── UserRepository.h
│   │
│   ├── models/
│   │   ├── Task.h
│   │   └── User.h
│   │
│   └── utils/
│       └── JwtUtils.h
│
└── README.md
```
