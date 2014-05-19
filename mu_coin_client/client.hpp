#pragma once

#include <mu_coin_store/db.hpp>
#include <mu_coin_wallet/wallet.hpp>
#include <QtGui>
#include <QtWidgets>

namespace mu_coin_client {
    class client : QObject
    {
    public:
        client (int, char **);
        ~client ();
        mu_coin_store::block_store_db store;
        mu_coin::ledger ledger;
        mu_coin_wallet::wallet wallet;
        
        QApplication application;
        QMainWindow main_window;
        QStackedWidget main_stack;
        
        QWidget send_coins_window;
        QVBoxLayout send_coins_layout;
        QPushButton send_coins_cancel;
        
        QWidget wallet_window;
        QVBoxLayout wallet_layout;
        QStringListModel wallet_model;
        QModelIndex wallet_model_selection;
        QLabel wallet_balance_label;
        QListView wallet_view;
        QPushButton send_coins;
        QPushButton wallet_add_key;
        
        QMenu wallet_key_menu;
        QAction wallet_key_copy;
        QAction wallet_key_cancel;
        
        QWidget new_key_window;
        QVBoxLayout new_key_layout;
        QLabel new_key_password_label;
        QLineEdit new_key_password;
        QPushButton new_key_add_key;
        QPushButton new_key_cancel;
    private:
        QStringList keys;
    private:
        void refresh_wallet ();
    };
}