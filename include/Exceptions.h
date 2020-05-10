#ifndef BEERGAME_EXCEPTIONS_H
#define BEERGAME_EXCEPTIONS_H

#include <exception>

//!  The Exceptions Class.
/*!
 * The exceptions class deals with custom exceptions which are used to ensure smooth use and operation of game logic.
 *
*/

class cExceptions : virtual public std::exception {

protected:

    int error_number;               /*!< Error Number. */
    int error_offset;               /*!< Error Offset. */
    const char *error_message;      /*!< Error message. */

    // custom error messages. I recommend you add any custom exception handling here and use them as errors
    // this is better because you can globally edit these errors in case you want ot change wording

    // ID ERRORS
    const char *_id_unique_err = "this ID already exists. ID's are unique attributes"; /*!< Unique ID error. */
    const char *_id_inexistent_scope_err = "this ID does not exist in the current scope."; /*!< Inexistent ID in scope error.*/
    const char *_id_unset_err = "this ID does not exist in the current scope."; /*!< Unset ID error. */

    // MEMORY ERRORS
    const char *_mem_players_err = "The players memory is not cleared."; /*!< Players vector memory flush error. */
    const char *_mem_ordersTBE_err = "The orders to be executed memory is not cleared."; /*!< OrdersToBeExecuted map memory flush error */
    const char *_mem_shipmentsTBE_err = "The shipments to be executed memory is not cleared."; /*!< ShipmentsToBeExecuted map memory flush error */
    const char *_mem_consumer_demand_err = "The consumer demand memory is not cleared."; /*!< ConsumerDemand vector memory flush error */


    // GAME CLASS
    const char *_zero_value_err = "This value can't be 0."; /*!< Value can't hold 0 error message. */
    const char *_negative_value_err = "This value can't be negative."; /*!< Value can't be negative error message. */
    const char *_factory_action_err = "Unable to execute this action from the factory player."; /*!< Factory action error message. */
    const char *_retailer_action_err = "Unable to execute this action from the retailer player."; /*!< Retailer action error message. */
    const char *_distributor_action_err = "Unable to execute this action from the distributor player."; /*!< Distributor action error message. */
    const char *_wholesaler_action_err = "Unable to execute this action from the wholesaler player."; /*!< Wholesaler action error message. */
    const char *_role_inexistent_err = "This role number does not exits."; /*!< Inexistent player role error message. */
    const char *_data_copy_err = "The data failed to copy.";
    const char *_overflow_data_err = "The elements in this container exceed the limit specified.";
    const char *_info_code_small_err = "The info code must contain 4 digits."; /*!< Info code format error message. */
    const char *_no_players_inGame_err = "No players are in the game. It's possible that the game memory has been flushed."; /*!< No players in game error message. */
    const char *_critical_logic_gen_err = "Critical logic error. This might interfere with the game logic."; /*!< Critical logic conflict error message. */
    const char *_overflow_player_num_err = "Overflow in number of players. Number of players can't exceed 4."; /*!< Player overflow error message. */
    const char *_underflow_player_num_err = "Underflow in number of players. Number of players must be 4."; /*!< player underflow error message. */
    const char *_critical_logic_nonmatching_ids_err = "Critical logic error. IDs in players vector don't match stored IDs."; /*!< Critical logic IDs conflict error message. */

    // OTHER
    const char *_invalid_errNum_err = "invalid_error_number. default exception thrown"; /*!< Invalid error number error message. */
    const char *_idx_of_range_err = "index out of range error."; /*!< Index out of range error message. */
    const char *_weeks_limit_reached_err = "total weeks limit has been reached."; /*!< Total weeks have been reached error message. */


public:
    // Constructos / Destructor
    //! Default constructor :
    /**
     * The default constructor creates a default cExceptions instance.
    */
    cExceptions();
    //! Parametric constructor :
    /**
    The parametric constructor creates a custom cExceptions instance.
     @param msg the error message.
     @param err_num the error number.
     @param err_off the error offset.
    */
    explicit cExceptions(const char *msg, int err_num, int err_off);

    //! what() :
    /**
    returns the error message associated with the current instance.
     @return the error message.
    */
    const char *what() const noexcept override;

    // Getters
    //! Get the error number
    /**
     * Getter for the error number.
     * @return the error number.
     */
    virtual int getErrorNumber() const noexcept;
    //! Get the error offset
    /**
     * Getter for the error offset.
     * @return the error offset.
     */
    virtual int getErrorOffset() const noexcept;

    //Exceptions
    //! ID error
    /**
     * Handles all errors related to the UniqueID class and instances. The table below illustrates the errors and there meanings (Default means any int value).
 <table>
  <tr>
    <th>Message</th>
    <th>Error Number</th>
    <th>Error Offset</th>
  </tr>
  <tr>
    <td>ID Unique Error</td>
    <td>1</td>
    <td>0</td>
  </tr>
  <tr>
    <td>ID Inexistent In Scope</td>
    <td>2</td>
    <td>0</td>
  </tr>
  <tr>
    <td>ID Not Initialized Error</td>
    <td>3</td>
    <td>0</td>
  </tr>
  <tr>
    <td>Throws a Default Error</td>
    <td>DEFAULT(-1)</td>
    <td>-1</td>
  </tr>
</table>
     * @param error  the error number.
     * @return current cExceptions instance.
     */
    virtual cExceptions id_error(int) noexcept;
    //! Memory Leak Errors
    /**
     * Handles all errors related to the possible memory leaks in the Game class. The table below illustrates the errors and there meanings (Default means any int value).
    <table>
    <tr>
    <th>Message</th>
    <th>Error Number</th>
    <th>Error Offset</th>
    </tr>
    <tr>
    <td>Players Memory Flush Error</td>
    <td>1</td>
    <td>1</td>
    </tr>
    <tr>
    <td>OrdersTBE Memory Flush Error</td>
    <td>2</td>
    <td>1</td>
    </tr>
    <tr>
    <td>ShipmentsTBE Memory Flush Error</td>
    <td>3</td>
    <td>1</td>
    </tr>
    <tr>
    <td>ConsumerDemand Memory Flush Error</td>
    <td>4</td>
    <td>1</td>
    </tr>
    <tr>
    <td>Throws a default error</td>
    <td>DEFAULT (-1)</td>
    <td>-1</td>
    </tr>
    </table>
     * @param error  the error number.
     * @return current cExceptions instance.
     */
    virtual cExceptions memory_leaks_error(int) noexcept;
    //! Game Class Errors
    /**
     * Handles all errors related to general Game class exceptions. The table below illustrates the errors and there meanings (Default means any int value).
<table>
  <tr>
    <th>Message</th>
    <th>Error Number</th>
    <th>Error Offset</th>
  </tr>
  <tr>
    <td>No Players In Game Error</td>
    <td>1</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Unexpected Negative Value Error</td>
    <td>2</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Unexpected 0 Value Error</td>
    <td>3</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Small Info Code Error</td>
    <td>4</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Inexistent Role Error</td>
    <td>5</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Unhandled Factory Action Error</td>
    <td>6</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Unhandled Distributor Action Error</td>
    <td>7</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Unhandled Wholesaler Action Error</td>
    <td>8</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Unhandled Retailer Action Error</td>
    <td>9</td>
    <td>4</td>
  </tr>
  <tr>
    <td>General Critical Logic Error</td>
    <td>10</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Player Number Overflow Error</td>
    <td>11</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Player Number Underflow Error</td>
    <td>12</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Critical Logic Error : Unexpected ID Mismatch</td>
    <td>13</td>
    <td>4</td>
  </tr>
  <tr>
    <td>Throws a default error</td>
    <td>DEFAULT (-1)</td>
    <td>-1</td>
  </tr>
</table>
     * @param err  the error number.
     * @return current cExceptions instance.
     */
    virtual cExceptions game_class_errors(int) noexcept;
    //! Index range errors.
    /**
     * Handles the index of players/games out of range exception.
     * @return current cExceptions instance.
     */
    virtual cExceptions idx_range_error() noexcept;
    //! Weekly limit errors.
    /**
     * Handles the weekly limit exception.
     * @return current cExceptions instance.
     */
    virtual cExceptions weeks_limit_error() noexcept;

};


#endif //BEERGAME_EXCEPTIONS_H
