#include <iostream>

#include "ann/ffn.hpp"

#include <mlpack/methods/ann/layer/layer_types.hpp>


class PolicyEstimator()
{
		PolicyEstimator()
	{	arma::mat observation;
		arma::mat 
		FFN policy_estimator();
		policy_estimator.Add(Sequential<>)
	}

	arma::mat predict(arma::mat obs_state)
	{
		arma::mat value;
		value_estimator.Predict(obs_state, &value);
		return value;
	}

	void train(arma::mat obs_state, arma:mat target, arma::mat action)
	{
		arma::mat combined = arma::mat join_rows(target, action)
		policy_estimator.Train(obs_state, combined);

	}

}


class ValueEstimator()
{
	ValueEstimator()
	{	arma::mat observation;
		FFN value_estimator();
		value_estimator.Add(Sequential<>)
	}

	arma::mat predict(arma::mat obs_state)
	{
		arma::mat value;
		value_estimator.Predict(obs_state, &value);
		return value;
	}

	void train(arma::mat obs_state, arma:mat target)
	{
		value_estimator.Train(obs_state, target);
	}


}


int main()
{	


  const std::string environment = "MountainCar-v0";
  const std::string host = "kurg.org";
  const std::string port = "4040";

  double reward = 0;
  size_t totalSteps = 0;

  Environment env(host, port, environment);
  env.compression(9);
  env.monitor.start("./dummy/", true, true);
  double discount_factor = 0.1;
  env.reset();
  env.render();
  value_network = ValueEstimator();
  policy_network = PolicyEstimator();
  arma::mat = env.action_space;
  arma::mat current_obs, action_probs, action, next_obs, next_value, target, error;
  while (1)
  {		
  		current_obs = env.observation();
  		action_probs = policy_network.predict(current_obs);
  		double best_action_prob = 0;
  		int best_action_index = 0;
  		for(int i=0;i < action_space.n_rows; i++)
  		{
  			if(arma::mat(i)>best_action)
  			{	best_action_prob = arma::mat(i);
  				best_action_index = i;
  			}
  		}

  		action = action_space(best_action_index);
  		env.step(action);
  		reward = env.reward;
  		next_obs = env.observation();

  		next_value = value_network.predict(next_obs);
  		target = reward + discount_factor*next_value;
  		error = target - value_network.predict(current_obs);

  		value_network.train(obs, target);

  		policy_network.train(obs, error, action);
}

  return 0;
}