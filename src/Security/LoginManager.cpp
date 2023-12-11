//
// Created by Kasper de Bruin on 06/12/2023.
//

#include "LoginManager.h"
#include "../Application.h"
#include <cstring>

bool KBTools::Security::LoginManager::m_isLoggedIn = false;

bool KBTools::Security::LoginManager::Login(const char *username, const char *password) {
    //TODO: Implement login with database
//    if(strcmp(username, "admin") != 0 || strcmp(password, "admin") != 0) {
//        return false;
//    }
//    m_isLoggedIn = true;
    //Check if the username and password are correct
    //If they are correct, set m_isLoggedIn to true
    //If they are not correct, return false
    CORE_INFO("Username: {}", username);


    std::string query = fmt::format("SELECT * FROM User WHERE name = '{}' AND password = '{}';", username, password);

    HummingBird::Sql::SqlResult result = HummingBird::Sql::SqlManager::GetMainConnection()->Query(query);
    if(result.WasSuccessful()){
        if(result.GetResult()->row_count == 1) {
            m_isLoggedIn = true;
            return true;
        }
      }
    return false;
}

bool KBTools::Security::LoginManager::Register(const char *username, const char *password) {
    //TODO: Implement register with database
    return true;
}

bool KBTools::Security::LoginManager::Logout() {
    //TODO: Implement logout with database
    m_isLoggedIn = false;
    return true;
}

bool KBTools::Security::LoginManager::IsLoggedIn() {
    return m_isLoggedIn;
}


