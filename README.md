# Установка Зависимоти

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


sudo apt install -y libdrogon-dev
dpkg -l | grep drogon

sudo apt install -y libmysqlclient-dev

sudo apt install -y default-libmysqlclient-dev

mkdir task-manager-cpp
cd task-manager-cpp
```

---

# Сборка

```bash
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=/usr/local/lib/cmake/Drogon
make -j$(nproc)
```

---

# Запуск

```bash
./TaskManager
```

---

# РОУТЫ

```bash
/  - GET home page (GET)

/tasks - GET Example tasks(GET)

/tasks - POST CREATE Example tasks(POST)

/user -  create TEST user(GET)
```

---

# СТРУКТУРА

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
