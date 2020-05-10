#include "Exceptions.h"


cExceptions::cExceptions() {
    this->error_message = "default_error";
    this->error_number = -1;
    this->error_offset = -1;
}

cExceptions::cExceptions(const char *msg, int err_num, int err_off) {
    this->error_message = msg;
    this->error_number = err_num;
    this->error_offset = err_off;
}

const char *cExceptions::what() const noexcept {
    return error_message;
}

int cExceptions::getErrorNumber() const noexcept {
    return this->error_number;
}

int cExceptions::getErrorOffset() const noexcept {
    return this->error_offset;
}

cExceptions cExceptions::id_error(int error) noexcept {
    this->error_offset = 0;
    switch (error) {
        case 1:
            this->error_number = error;
            this->error_message = _id_unique_err;
            break;
        case 2:
            this->error_number = error;
            this->error_message = _id_inexistent_scope_err;
            break;
        case 3:
            this->error_number = error;
            this->error_message = _id_unset_err;
            break;
        default:
            this->error_number = -1;
            this->error_offset = -1;
            this->error_message = _invalid_errNum_err;
            break;
    };
    return (*this);
}

cExceptions cExceptions::idx_range_error() noexcept {
    this->error_message = _idx_of_range_err;
    this->error_number = 1;
    this->error_offset = 3;
    return (*this);
}

cExceptions cExceptions::weeks_limit_error() noexcept {
    this->error_message = _weeks_limit_reached_err;
    this->error_number = 2;
    this->error_offset = 3;
    return (*this);
}

cExceptions cExceptions::memory_leaks_error(int error) noexcept {
    this->error_offset = 1;
    switch (error) {
        case 1:
            this->error_number = error;
            this->error_message = _mem_players_err;
            break;
        case 2:
            this->error_number = error;
            this->error_message = _mem_ordersTBE_err;
            break;
        case 3:
            this->error_number = error;
            this->error_message = _mem_shipmentsTBE_err;
            break;
        case 4:
            this->error_number = error;
            this->error_message = _mem_consumer_demand_err;
            break;
        default:
            this->error_offset = -1;
            this->error_number = -1;
            this->error_message = _invalid_errNum_err;
            break;
    };
    return (*this);
}

cExceptions cExceptions::game_class_errors(int err) noexcept {
    this->error_offset = 4;
    switch (err) {
        case 1:
            this->error_message = _no_players_inGame_err;
            this->error_number = err;
            break;
        case 2:
            this->error_message = _negative_value_err;
            this->error_number = err;
            break;
        case 3:
            this->error_message = _zero_value_err;
            this->error_number = err;
            break;
        case 4:
            this->error_message = _info_code_small_err;
            this->error_number = err;
            break;
        case 5:
            this->error_number = err;
            this->error_message = _role_inexistent_err;
            break;
        case 6:
            this->error_number = err;
            this->error_message = _factory_action_err;
            break;
        case 7:
            this->error_number = err;
            this->error_message = _distributor_action_err;
            break;
        case 8:
            this->error_number = err;
            this->error_message = _wholesaler_action_err;
            break;
        case 9:
            this->error_number = err;
            this->error_message = _retailer_action_err;
            break;
        case 10:
            this->error_number = err;
            this->error_message = _critical_logic_gen_err;
            break;
        case 11:
            this->error_number = err;
            this->error_message = _overflow_player_num_err;
            break;
        case 12:
            this->error_number = err;
            this->error_message = _underflow_player_num_err;
            break;
        case 13:
            this->error_number = err;
            this->error_message = _critical_logic_nonmatching_ids_err;
            break;
        case 14:
            this->error_number = err;
            this->error_message = _data_copy_err;
            break;
        case 15:
            this->error_number = err;
            this->error_message = _overflow_data_err;
            break;
        default:
            this->error_offset = -1;
            this->error_number = -1;
            this->error_message = _invalid_errNum_err;
            break;
    }
    return (*this);
}
